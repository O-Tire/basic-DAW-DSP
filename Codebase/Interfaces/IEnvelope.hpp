#pragma once


class IEnvelope
{
public:
    
    /** @param time Time since the envelope began. (in seconds)
     *  @param releaseTime Time since the key was released.
     *  Zero means that key hasn't been released yet. (in seconds)
     */
    virtual float GetValue(float time, float releaseTime) const;
};