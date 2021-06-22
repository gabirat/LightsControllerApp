#pragma once

#include <string>
#include <vector>
#include <chrono>
#include <iostream>
#include <stdint.h>
#include "SerialPort.h"

struct Color {
public:
    uint8_t r;
    uint8_t g;
    uint8_t b;
    Color(uint8_t r, uint8_t g, uint8_t b) :
        r(r), g(g), b(b) {
    };
};

struct Keyframe {
public:
    float timestamp;
    Color color;
};

class LEDEffect {
public:
    float durationInSeconds;
    std::vector<Keyframe> keyframes;
    LEDEffect(std::vector<Keyframe> kf);
};

class HardwareController : public SerialPort {
private:
    bool effect_in_progress;
public:
	HardwareController(char* port);
	void play_effect(LEDEffect effect);
    void set_color(Color c);
    bool get_effect_in_progress() const;
};