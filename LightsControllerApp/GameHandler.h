#pragma once

#include <vector>
#include <memory>
#include <thread>
#include <mutex>
#include <Poco/Net/HTTPServer.h>
#include "HardwareController.h"
#include "GSIRequestHandlerFactory.h"
#include "EventHandler.h"

class GameHandler {
private:
	std::shared_ptr<Poco::Net::HTTPServer> http_srv;
	std::shared_ptr<HardwareController> led_controller;
	std::vector<EventHandler> event_handlers;
	std::string gsi_path;
	Poco::UInt16 port;
	std::mutex data_mutex;
	Poco::JSON::Object data;

public:
	GameHandler(std::shared_ptr<HardwareController> hc, std::string gsi_path, Poco::UInt16 port);
	void update_data(Poco::JSON::Object::Ptr data);
	Poco::JSON::Object get_data();
	std::string get_gsi_path() const;
	void run();
	void stop();
};

