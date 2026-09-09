#define MINIAUDIO_IMPLEMENTATION
#include "libraries/miniaudio.h"
#include <iostream>
#include <vector>

// Example: 16-bit mono PCM samples at 44.1 kHz
std::vector<int16_t> samples;

ma_uint64 cursor = 0; // playback position

// Callback: miniaudio pulls audio data here
void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount) {
    int16_t* out = (int16_t*)pOutput;

    for (ma_uint32 i = 0; i < frameCount; i++) {
        if (cursor < samples.size()) {
            out[i] = samples[cursor++];
        } else {
            out[i] = 0; // silence after samples end
        }
    }

    (void)pInput; // unused
}

int main() {
    // Generate a simple sine wave for demonstration
    double frequency = 440.0; // A4
    double sampleRate = 44100.0;
    double amplitude = 3000.0;
    int durationSeconds = 2;

    int totalSamples = (int)(durationSeconds * sampleRate);
    samples.resize(totalSamples);

    for (int i = 0; i < totalSamples; i++) {
        samples[i] = (int16_t)(amplitude * sin((2.0 * MA_PI * frequency * i) / sampleRate));
    }

    // Configure playback device
    ma_device_config config = ma_device_config_init(ma_device_type_playback);
    config.playback.format   = ma_format_s16;
    config.playback.channels = 1;
    config.sampleRate        = (ma_uint32)sampleRate;
    config.dataCallback      = data_callback;

    ma_device device;
    if (ma_device_init(NULL, &config, &device) != MA_SUCCESS) {
        std::cerr << "Failed to initialize playback device.\n";
        return -1;
    }

    if (ma_device_start(&device) != MA_SUCCESS) {
        std::cerr << "Failed to start playback device.\n";
        ma_device_uninit(&device);
        return -1;
    }

    std::cout << "Playing sine wave...\n";
    getchar(); // wait until user presses Enter

    ma_device_uninit(&device);
    return 0;
}
