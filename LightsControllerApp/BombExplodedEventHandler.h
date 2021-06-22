#pragma once
#include "EventHandler.h"

namespace GameEvent {

class BombExplodedEventHandler : public EventHandler {
public:
	BombExplodedEventHandler(std::shared_ptr<HardwareController> hc);
};

};



