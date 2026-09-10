#pragma once

#include "../Libraries/dr_wav.h"
#include "Constants.hpp"
#include <vector>


/** Turns WAV files in samples. Use 'LoadClip()' to load a file, and use the 'Clips' vector to find your
loaded samples. */
class ClipManager
{
private:

    float _sampleRate;

public:

    std::vector<Clip> Clips;
    
    ClipManager(float sampleRate);

    /** Loads WAV files and turns them into samples and pushes them to 'Clips'. */
    void LoadClip(const char* path);
};