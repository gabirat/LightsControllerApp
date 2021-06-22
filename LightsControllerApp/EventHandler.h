#pragma once

#include <memory>
#include "HardwareController.h"

namespace GameEvent {

	enum class EventType {
		None = 0,
		BOMB_EXPLODED, BOMB_DEFUSED, BOMB_PLANTED
	};

	class EventHandler {
	protected:
		std::shared_ptr<HardwareController> led_controller;
		LEDEffect effect;
		EventType event_type;
	public:
		EventHandler(std::shared_ptr<HardwareController> hc);
		EventType get_event_type() const;
		virtual void handle_event();
	};

};



