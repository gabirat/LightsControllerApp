#include "WinCTEventHandler.h"

namespace GameEvent {
    WinCTEventHandler::WinCTEventHandler(std::shared_ptr<HardwareController> hc) :
        EventHandler(hc) {
        event_type = EventType::WIN_CT;
        effect = LEDEffect(std::vector<Keyframe> {
            Keyframe{ 0.0f, Color(0, 0, 0) },
            Keyframe{ 3.0f, Color(0, 0, 255) }
        });
    }
};