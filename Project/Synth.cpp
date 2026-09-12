#include "Synth.hpp"
#include <cmath>
#include <corecrt_math_defines.h>


float Synth::GetSample(int sampleIdx, float frequency, int sampleRate) const
{
    double x = sin((double)(2.0f * M_PI * frequency / 256    * sampleIdx / sampleRate));
    double y = sin((double)(2.0f * M_PI * frequency * 2      * sampleIdx / sampleRate));
    
    double result = x * y;
    result /= 2;
    
    return (float)result;
}