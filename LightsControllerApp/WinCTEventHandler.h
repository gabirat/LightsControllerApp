#pragma once
#include "EventHandler.h"

namespace GameEvent {

class WinCTEventHandler : public EventHandler {
public:
	WinCTEventHandler(std::shared_ptr<HardwareController> hc);
};

};