#include "WinTEventHandler.h"

namespace GameEvent {
    WinTEventHandler::WinTEventHandler(std::shared_ptr<HardwareController> hc) :
        EventHandler(hc) {
        event_type = EventType::WIN_T;
        effect = LEDEffect(std::vector<Keyframe> {
            Keyframe{ 0.0f, Color(0, 0, 0) },
                Keyframe{ 3.0f, Color(255, 0, 0) }
        });
    }
};