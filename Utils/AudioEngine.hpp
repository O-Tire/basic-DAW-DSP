#pragma once

#include "miniaudio.h"
#include "Constants.hpp"


class AudioEngine
{
private:

    ma_device* _device = nullptr;
    
public:
    
    int playhead = 0;
    
    Clip samples;
    
    AudioEngine(float sampleRate);
    
    ~AudioEngine();
    
    void PlaySamples(Clip samples);
    
    static void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);
};