#include "GameHandler.h"

GameHandler::GameHandler(std::shared_ptr<HardwareController> hc, std::string gsi_path, Poco::UInt16 port) : 
	led_controller(hc), 
	gsi_path(gsi_path),
	port(port) {
	http_srv = std::make_shared<Poco::Net::HTTPServer>(
		new GSIRequestHandlerFactory(this),
		Poco::Net::ServerSocket(port),
		new Poco::Net::HTTPServerParams);

}

void GameHandler::update_data(Poco::JSON::Object::Ptr data) {
	data_mutex.lock();
	this->data = *data;
	data_mutex.unlock();
}

Poco::JSON::Object GameHandler::get_data() {
	data_mutex.lock();
	auto ret = data;
	data_mutex.unlock();
	return ret;
}

std::string GameHandler::get_gsi_path() const {
	return gsi_path;
}

void GameHandler::run() {
	http_srv->start();
}

void GameHandler::stop() {
	http_srv->stop();
}
