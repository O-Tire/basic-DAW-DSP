#pragma once

#include "IEnvelope.hpp"


class ADSR : IEnvelope
{
public:

    float Attack;
    
    float Decay;
    
    float Sustain;
    
    float Release;
    
    ADSR(float a, float d, float s, float r);
    
    virtual float GetValue(float time, float releaseTime = 0) const override;
};