#pragma once

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <Poco/Net/HTTPServer.h>
#include "HardwareController.h"
#include "GSIRequestHandlerFactory.h"
#include "EventHandlerFactory.h"

class GameHandler {
private:
	std::shared_ptr<Poco::Net::HTTPServer> http_srv;
	std::shared_ptr<HardwareController> led_controller;
	std::queue<std::shared_ptr<GameEvent::EventHandler>> event_queue;
	std::string gsi_path;
	Poco::UInt16 port;
	std::mutex data_lock;
	Poco::JSON::Object data;
	bool running;
	bool data_has_changed;
	std::thread event_loop_thread;
	std::thread queue_handler_thread;
	void check_events();
	void handle_queue();

public:
	GameHandler(std::shared_ptr<HardwareController> hc, std::string gsi_path, Poco::UInt16 port);
	void update_data(Poco::JSON::Object::Ptr data);
	Poco::JSON::Object get_data();
	std::string get_gsi_path() const;
	void run();
	void stop();
};

