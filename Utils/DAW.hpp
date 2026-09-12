#pragma once

#include "AudioEngine.hpp"
#include "AssetLoader.hpp"

class AudioEngine;
class AssetLoader;
class Sequencer;
class Project;


/** Loads the entire system and runs projects. */
class DAW
{
private:

    AudioEngine* AE;
    
    AssetLoader* AL;
    
    Sequencer* SE;

public:

    float SampleRate = 48000;
    
    float Tempo = 120;

    DAW();
    
    ~DAW();
    
    void RunProject(Project* project);
};