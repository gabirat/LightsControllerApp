#pragma once

#include <vector>
#include <memory>
#include <thread>
#include <mutex>
#include <Poco/Net/HTTPServer.h>
#include "GSIRequestHandlerFactory.h"
#include "EventHandler.h"

class GameHandler {
private:
	std::shared_ptr<Poco::Net::HTTPServer> http_srv;
	std::vector<EventHandler> event_handlers;
	std::mutex data_mutex;
	Poco::JSON::Object new_data;
	Poco::JSON::Object previous_data;

public:
	GameHandler();
	void update_data(Poco::JSON::Object::Ptr data);
	Poco::JSON::Object get_new_data();
	Poco::JSON::Object get_previous_data();
	void run();
	void stop();
};

