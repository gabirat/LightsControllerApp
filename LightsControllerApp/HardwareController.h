#pragma once

#include <string>
#include <vector>
#include <chrono>
#include "SerialPort.h"

struct Color {
public:
    char r;
    char g;
    char b;
    Color(char r, char g, char b) :
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