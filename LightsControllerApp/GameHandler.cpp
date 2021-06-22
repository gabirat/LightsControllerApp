#include "GameHandler.h"

void GameHandler::check_events() {
	while (running) {
		data_lock.lock();
		if (data.has("previously") &&
			data.getObject("previously")->has("round") &&
			data.getObject("previously")->getObject("round")->has("bomb") &&
			(data.getObject("previously")->getObject("round")->getValue<std::string>("bomb") == "planted")) {
			if (data.has("round") &&
				data.getObject("round")->has("bomb") &&
				(data.getObject("round")->getValue<std::string>("bomb") == "exploded")) {
				queue_lock.lock();
				event_queue.push(GameEvent::EventHandlerFactory::create_event_handler(GameEvent::EventType::BOMB_EXPLODED, led_controller));
				queue_lock.unlock();
			}
		}
		data_lock.unlock();
	}
}

void GameHandler::handle_queue() {
	while (running) {
		queue_lock.lock();
		if (event_queue.empty()) {
			continue;
		}
		auto& ev = event_queue.front();
		ev->handle_event();
		event_queue.pop();
		queue_lock.unlock();
		Sleep(16);
	}
}

GameHandler::GameHandler(std::shared_ptr<HardwareController> hc, std::string gsi_path, Poco::UInt16 port) :
	led_controller(hc), 
	gsi_path(gsi_path),
	port(port),
	running(false) {
	http_srv = std::make_shared<Poco::Net::HTTPServer>(
		new GSIRequestHandlerFactory(this),
		Poco::Net::ServerSocket(port),
		new Poco::Net::HTTPServerParams);
}

void GameHandler::update_data(Poco::JSON::Object::Ptr data) {
	data_lock.lock();
	this->data = *data;
	data_lock.unlock();
}

Poco::JSON::Object GameHandler::get_data() {
	data_lock.lock();
	auto ret = data;
	data_lock.unlock();
	return ret;
}

std::string GameHandler::get_gsi_path() const {
	return gsi_path;
}

void GameHandler::run() {
	running = true;
	http_srv->start();
	event_loop_thread = std::thread(&GameHandler::check_events, this);
	queue_handler_thread = std::thread(&GameHandler::handle_queue, this);
}

void GameHandler::stop() {
	running = false;
	http_srv->stop();
	event_loop_thread.join();
	queue_handler_thread.join();
}
