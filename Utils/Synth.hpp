#pragma once
#include "Constants.hpp"


class Synth
{
private:
    static float CalculateSample(int time, float frequency, float sampleRate);
    
public:
    static Clip Synthesize(float frequency, float duration, float sampleRate);
};