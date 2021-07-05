#include "BombExplodedEventHandler.h"

namespace GameEvent {
    BombExplodedEventHandler::BombExplodedEventHandler(std::shared_ptr<HardwareController> hc) :
        EventHandler(hc) {
        event_type = EventType::BOMB_EXPLODED;
        effect = LEDEffect(std::vector<Keyframe> {
            Keyframe{ 0.0f, Color(0, 0, 0) },
            Keyframe{ 0.5f, Color(255, 0, 0 ) },
            Keyframe{ 3.0f, Color(0, 0, 0) }
        });
    }
};