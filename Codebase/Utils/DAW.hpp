#pragma once

#include "AudioEngine.hpp"
#include "AssetLoader.hpp"
#include <string>

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

    /** Shouldn't change after DAW initialization. */
    float SampleRate = 48000;
    
    float Tempo = 120;

    DAW();
    
    ~DAW();
    
    /** Path to a Lua file. */
    void RunProject(std::string path);
};