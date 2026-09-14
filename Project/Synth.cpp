#include "Synth.hpp"
#include <cmath>
#include <corecrt_math_defines.h>


float Synth::GetSample(int sampleIdx, float frequency, int sampleRate) const
{
    float x = 2.0f * M_PI * frequency / 8.f * sampleIdx / sampleRate;
    
    float result = x - floor(x) - .5f;
    result /= 8;
    
    return result;
}