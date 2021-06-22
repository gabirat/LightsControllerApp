#pragma once

#include "BombExplodedEventHandler.h"

namespace GameEvent {

	class EventHandlerFactory {
	public:
		static std::shared_ptr<EventHandler> create_event_handler(EventType et, std::shared_ptr<HardwareController> hc);
	};

};



