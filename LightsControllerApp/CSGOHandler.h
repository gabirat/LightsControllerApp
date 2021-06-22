#pragma once

#include "GameHandler.h"

class CSGOHandler : public GameHandler {
private:
public:
	CSGOHandler(std::shared_ptr<HardwareController> hc, std::string gsi_path, Poco::UInt16 port);
};

