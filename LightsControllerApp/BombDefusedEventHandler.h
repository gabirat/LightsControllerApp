#pragma once
#include "EventHandler.h"

namespace GameEvent {

    class BombDefusedEventHandler : public EventHandler {
    public:
        BombDefusedEventHandler(std::shared_ptr<HardwareController> hc);
    };

};