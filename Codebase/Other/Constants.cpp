#include "Constants.hpp"

int SecondsToSamples(float seconds, float sampleRate)
{
    return (int)floor(seconds * sampleRate);
}