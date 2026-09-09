#define MINIAUDIO_IMPLEMENTATION
#include "libraries/miniaudio.h"
#include <iostream>
#include <vector>
#include "utils/synth.hpp"



// Example: 16-bit mono PCM samples at 44.1 kHz
std::vector<float> samples;
ma_uint64 cursor = 0; // playback position

// Callback: miniaudio pulls audio data here
void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount) {
    float* out = (float*)pOutput;

    for (ma_uint32 i = 0; i < frameCount; i++) {
        if (cursor < samples.size()) {
            out[i] = samples[cursor++];
        } else {
            out[i] = 0; // silence after samples end
        }
    }
}

int main() {
    // Generate a simple sine wave for demonstration
    float sampleRate = 44100.0;
    float amplitude = 1;
    int durationSeconds = 10;

    int totalSamples = (int)(durationSeconds * sampleRate);
    samples.resize(totalSamples);

    for (int i = 0; i < totalSamples; i++) {
        samples[i] = Synth::Synthesize(i, sampleRate);
    }

    // Configure playback device
    ma_device_config config = ma_device_config_init(ma_device_type_playback);
    config.playback.format   = ma_format_f32;
    config.playback.channels = 1;
    config.sampleRate        = (ma_uint32)sampleRate;
    config.dataCallback      = data_callback;

    ma_device device;
    ma_device_init(NULL, &config, &device);
    ma_device_start(&device);

    std::cout << "Playing sine wave...\n";
    getchar(); // wait until user presses Enter

    ma_device_uninit(&device);
    return 0;
}
