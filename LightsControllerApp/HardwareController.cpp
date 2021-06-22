#include "HardwareController.h"

HardwareController::HardwareController(char* port) : 
    SerialPort(port), effect_in_progress(false) {
}

void HardwareController::play_effect(LEDEffect effect) {
    effect_in_progress = true;
    float time = 0.0f;
    int next_frame_idx = 1;
    Keyframe curr = effect.keyframes[0];
    Keyframe next = effect.keyframes[next_frame_idx];
    float r = 0.0f;
    float g = 0.0f;
    float b = 0.0f;
    float delta_time = 0.0f;
    
    while (time < effect.durationInSeconds) {
        std::chrono::steady_clock::time_point start_frame_time = std::chrono::steady_clock::now();
        if (time >= next.timestamp) {
            next_frame_idx++;
            curr = next;
            next = effect.keyframes[next_frame_idx];
        }
        float delta_r = (float)(next.color.r - curr.color.r) / (next.timestamp - curr.timestamp);
        float delta_g = (float)(next.color.g - curr.color.g) / (next.timestamp - curr.timestamp);
        float delta_b = (float)(next.color.b - curr.color.b) / (next.timestamp - curr.timestamp);
        r += delta_r * delta_time;
        g += delta_g * delta_time;
        b += delta_b * delta_time;
        r = r < 0.0f ? 0.0f : r;
        g = g < 0.0f ? 0.0f : g;
        b = b < 0.0f ? 0.0f : b;
        r = r > 255.0f ? 255.0f : r;
        g = g > 255.0f ? 255.0f : g;
        b = b > 255.0f ? 255.0f : b;

        set_color(Color((char)r, (char)g, (char)b));
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        delta_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start_frame_time).count() / 1000.0f;
        time += delta_time;
    }
    effect_in_progress = false;
}

void HardwareController::set_color(Color c) {
    char buff[3] = { c.b, c.g , c.r };
    this->writeSerialPort(buff, sizeof(buff));
}

bool HardwareController::get_effect_in_progress() const {
    return effect_in_progress;
}

LEDEffect::LEDEffect(std::vector<Keyframe> kf) : keyframes(kf) {
    durationInSeconds = kf[kf.size() - 1].timestamp;
}
