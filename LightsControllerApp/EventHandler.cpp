#include "EventHandler.h"

namespace GameEvent {
    EventHandler::EventHandler(std::shared_ptr<HardwareController> hc) : event_type(EventType::None), led_controller(hc) {
    }

    EventType EventHandler::get_event_type() const {
        return event_type;
    }

    void EventHandler::handle_event() {
        led_controller->play_effect(effect);
    }
};