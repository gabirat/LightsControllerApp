#include "LightsControllerApp.h"

void LightsControllerApp::run() {
	char com_port[] = "//.////COM3";
	led_controller = std::make_shared<HardwareController>(com_port);
	game_handlers.push_back(std::make_shared<CSGOHandler>());
}
