#pragma once

#include <string>
#include "SerialPort.h"

class HardwareController : SerialPort {
public:
	HardwareController(char* port);
	void play_effect();
};

