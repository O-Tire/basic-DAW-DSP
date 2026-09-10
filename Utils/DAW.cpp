#include "DAW.hpp"
#include "AudioEngine.hpp"
#include "ClipManager.hpp"
#include "Project.hpp"


DAW::DAW()
{
    AE = new AudioEngine(SAMPLE_RATE);
    CM = new ClipManager(SAMPLE_RATE);
}

DAW::~DAW()
{
    delete AE;
    delete CM;
    
    AE = nullptr;
    CM = nullptr;
}

void DAW::RunProject(Project* project)
{
    project->Run(AE, CM);
}