#pragma once

#include "AudioEngine.hpp"
#include "ClipManager.hpp"

class AudioEngine;
class ClipManager;
class Sequencer;
class Project;


/** Loads the entire system and runs projects. */
class DAW
{
private:

    AudioEngine* AE;
    
    ClipManager* CM;
    
    Sequencer* SE;

public:

    float SampleRate = 48000;

    DAW();
    
    ~DAW();
    
    void RunProject(Project* project);
};