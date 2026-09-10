#include "synth.hpp"
#include <corecrt_math_defines.h>


float Synth::CalculateSample(int time, float frequency, float sampleRate)
{
    double x = sin((double)(2.0f * M_PI * frequency / 256    * time / sampleRate));
    double y = sin((double)(2.0f * M_PI * frequency * 2      * time / sampleRate));
    
    double result = x * y;
    result /= 2;
    
    return (float)result;
}

SampleList Synth::Synthesize(float frequency, float duration, float sampleRate)
{
    float sampleSize = sampleRate * duration;
    SampleList samples((unsigned int)sampleSize);
    
    for (int i = 0; i < sampleSize; i++)
    {
        samples[i] = CalculateSample(i, frequency, sampleRate);
    }
    
    return samples;
}