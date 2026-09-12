#pragma once
#include "IVoice.hpp"


class Synth : public IVoice
{
    virtual float GetSample(int sampleIdx, float frequency) const override;
};