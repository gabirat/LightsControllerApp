#include "CSGOHandler.h"

CSGOHandler::CSGOHandler(std::shared_ptr<HardwareController> hc, std::string gsi_path, Poco::UInt16 port) : 
	GameHandler(hc, gsi_path, port) {
}
