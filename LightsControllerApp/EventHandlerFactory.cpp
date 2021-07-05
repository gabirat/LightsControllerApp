#include "EventHandlerFactory.h"

namespace GameEvent {

    std::shared_ptr<EventHandler> EventHandlerFactory::create_event_handler(EventType et, std::shared_ptr<HardwareController> hc) {
		switch (et) {
			case GameEvent::EventType::BOMB_EXPLODED:
				return std::make_shared<BombExplodedEventHandler>(hc);
			case GameEvent::EventType::BOMB_DEFUSED:
				return std::make_shared<BombDefusedEventHandler>(hc);
			case GameEvent::EventType::WIN_T:
				return std::make_shared<WinTEventHandler>(hc);
			case GameEvent::EventType::WIN_CT:
				return std::make_shared<WinCTEventHandler>(hc);
			//case GameEvent::EventType::BOMB_PLANTED:
			//	return std::make_shared<BombPlantedEventHandler>();
			default:
				return std::make_shared<EventHandler>(hc);
		}
        
    }
};