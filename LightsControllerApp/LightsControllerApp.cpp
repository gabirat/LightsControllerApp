#include "LightsControllerApp.h"

LightsControllerApp::LightsControllerApp() {
	char com_port[] = "\\\\.\\COM4";
	led_controller = std::make_shared<HardwareController>(com_port);
	game_handlers.push_back(std::make_shared<CSGOHandler>(led_controller, "/", 1337));
}

void LightsControllerApp::run() {
	for (auto& gh : game_handlers) {
		gh->run();
	}
	while (true) {

	}
}
