#pragma once
#include <vector>

class Synth
{
private:
    static float CalculateSample(float time, float frequency, float sampleRate);
    
public:
    static std::vector<float> Synthesize(float frequency, float duration, float sampleRate);
};