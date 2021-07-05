#pragma once
#include "EventHandler.h"

namespace GameEvent {

	class WinTEventHandler : public EventHandler {
	public:
		WinTEventHandler(std::shared_ptr<HardwareController> hc);
	};

};