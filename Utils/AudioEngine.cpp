#include "AudioEngine.hpp"

AudioEngine::AudioEngine(float sampleRate)
{
    // Playback device configuration:
    ma_device_config config = ma_device_config_init(ma_device_type_playback);
    config.playback.format = ma_format_f32;
    config.playback.channels = 1;
    config.sampleRate = sampleRate;
    config.dataCallback = data_callback;
    config.pUserData = this;

    _device = new ma_device();
    ma_device_init(nullptr, &config, _device);
}

AudioEngine::~AudioEngine()
{
    ma_device_uninit(_device);
    delete _device;
    _device = nullptr;
}

void AudioEngine::Start()
{
    ma_device_start(_device);
}

void AudioEngine::PlaySamples(SampleList samples)
{
    this->samples = samples;
    playhead = 0;
}

void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
    float* out = (float*)pOutput;
    AudioEngine* AE = reinterpret_cast<AudioEngine*>(pDevice->pUserData);

    for (ma_uint32 i = 0; i < frameCount; i++) {
        if (AE->playhead < AE->samples.size()) {
            out[i] = AE->samples[AE->playhead++];
        } else {
            out[i] = 0; // silence after samples end
        }
    }
}