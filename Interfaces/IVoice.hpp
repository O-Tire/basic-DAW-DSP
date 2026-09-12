#pragma once


class IVoice
{
public:

    virtual float GetSample(int sampleIdx, float frequency) const = 0;
};