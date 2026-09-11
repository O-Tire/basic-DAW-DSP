#pragma once

#include "../Libraries/dr_wav.h"
#include "Constants.hpp"


/** Loades assets such as WAV audio files or MIDI (WIP). */
class AssetLoader
{
private:

    float _sampleRate;

public:

    vector<Clip> Clips;
    
    AssetLoader(float sampleRate);

    /** Loads WAV files and turns them into samples and pushes them to 'Clips'. */
    void LoadClip(const char* path);
};