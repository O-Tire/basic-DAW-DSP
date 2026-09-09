#include "synth.hpp"
#include <corecrt_math_defines.h>


float Synth::CalculateSample(float time, float frequency, float sampleRate)
{
    float x = sin(2.0f * M_PI * frequency / 256    * time / sampleRate );
    float y = sin(2.0f * M_PI * frequency * 2    * time / sampleRate);
    
    float result = x * y;
    result /= 2;
    
    return result;
}

std::vector<float> Synth::Synthesize(float frequency, float duration, float sampleRate)
{
    float sampleSize = sampleRate * duration;
    std::vector<float> samples(sampleSize);
    
    for (int i = 0; i < sampleSize; i++)
    {
        samples[i] = CalculateSample(i, frequency, sampleRate);
    }
    
    return samples;
}