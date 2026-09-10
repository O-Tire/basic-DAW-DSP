#pragma once

#include "../Libraries/dr_wav.h"
#include "Constants.hpp"
#include <vector>


class ClipManager
{
private:

    float _sampleRate;

public:

    std::vector<SampleList> Clips;
    
    ClipManager(float sampleRate);

    /** Loads WAV files and turns them into samples and stores them in 'Clips'. */
    void LoadClip(const char* path);
};