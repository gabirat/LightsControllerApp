#pragma once

#include <vector>
#include "GameHandler.h"
#include "CSGOHandler.h"
#include "HardwareController.h"


class LightsControllerApp {
	std::vector<std::shared_ptr<GameHandler>> game_handlers;
	std::shared_ptr<HardwareController> led_controller;
public:
	LightsControllerApp();
	void run();
};

