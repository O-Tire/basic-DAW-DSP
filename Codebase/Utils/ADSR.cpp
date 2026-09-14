#include "ADSR.hpp"
#include <cmath>


ADSR::ADSR(float a, float d, float s, float r)
{
    Attack  = a;
    Decay   = d;
    Sustain = s;
    Release = r;
}

float ADSR::GetValue(float time, float releaseTime) const
{
    if (time < 0) return 0;
    
    if (time < Attack) return time / Attack;
    
    if (time < Attack + Decay) return 1 - ((time - Attack)/Decay) * (1 - Sustain);
    
    if (time >= Attack + Decay && releaseTime == 0) return Sustain;
    
    return fmax(
        (1 - (time - releaseTime) / Release) * Sustain,
        0
    );
}

bool ADSR::HasEnded(float releaseTime) const
{
    return releaseTime > Release;
}