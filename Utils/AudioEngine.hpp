#pragma once

#define MINIAUDIO_IMPLEMENTATION
#include "../libraries/miniaudio.h"
#include "Constants.hpp"


class AudioEngine
{
private:

    ma_device* _device = nullptr;

    static void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);

public:

    int playhead = 0;
    
    SampleList samples;

    AudioEngine();
    
    ~AudioEngine();
    
    void Start();
    
    void PlaySamples(SampleList samples);
};