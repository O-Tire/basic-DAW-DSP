#pragma once


class IVoice
{
public:
    virtual void GetSample(int sampleIdx) = 0;
};