#include "GameHandler.h"

GameHandler::GameHandler() {
	http_srv = std::make_shared<Poco::Net::HTTPServer>(new GSIRequestHandlerFactory(this), Poco::Net::ServerSocket(1337), new Poco::Net::HTTPServerParams);
}

void GameHandler::update_data(Poco::JSON::Object::Ptr data) {
	data_mutex.lock();
	previous_data = new_data;
	new_data = *data;
	data_mutex.unlock();
}

Poco::JSON::Object GameHandler::get_new_data() {
	data_mutex.lock();
	auto ret = new_data;
	data_mutex.unlock();
	return ret;
}

Poco::JSON::Object GameHandler::get_previous_data() {
	data_mutex.lock();
	auto ret = previous_data;
	data_mutex.unlock();
	return ret;
}

void GameHandler::run() {
	http_srv->start();
}

void GameHandler::stop() {
	http_srv->stop();
}
