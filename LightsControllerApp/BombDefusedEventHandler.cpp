#include "BombDefusedEventHandler.h"

namespace GameEvent {
    BombDefusedEventHandler::BombDefusedEventHandler(std::shared_ptr<HardwareController> hc) :
        EventHandler(hc) {
        event_type = EventType::BOMB_DEFUSED;
        effect = LEDEffect(std::vector<Keyframe> {
            Keyframe{ 0.0f, Color(0, 0, 0) },
            Keyframe{ 0.2f, Color(0, 0, 255) },
            Keyframe{ 0.4f, Color(0, 0, 0) },
            Keyframe{ 0.6f, Color(0, 0, 255) },
            Keyframe{ 0.8f, Color(0, 0, 0) },
            Keyframe{ 1.0f, Color(0, 0, 255) },
            Keyframe{ 1.2f, Color(0, 0, 0) },
            Keyframe{ 1.4f, Color(0, 0, 255) },
            Keyframe{ 1.6f, Color(0, 0, 0) }
        });
    }
};