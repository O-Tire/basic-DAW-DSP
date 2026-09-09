#include "synth.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

#define frequency 440.f



float Synth::Synthesize(float time, float sampleRate)
{
    float x = sin(2.0f * M_PI * frequency / 256    * time / sampleRate );
    float y = sin(2.0f * M_PI * frequency * 2    * time / sampleRate);
    
    float result = x * y;
    result /= 2;
    
    return result;
}