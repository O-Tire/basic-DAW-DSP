#pragma once

#include "AudioEngine.hpp"
#include "ClipManager.hpp"

class AudioEngine;
class ClipManager;
class Project;


/** Loads the entire system and runs projects. */
class DAW
{
private:

    AudioEngine* AE;
    
    ClipManager* CM;

public:

    DAW();
    
    ~DAW();
    
    void RunProject(Project* project);
};