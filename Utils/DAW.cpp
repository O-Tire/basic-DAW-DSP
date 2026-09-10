#include "DAW.hpp"
#include "AudioEngine.hpp"
#include "ClipManager.hpp"
#include "Project.hpp"
#include "Sequencer.hpp"


DAW::DAW()
{
    AE = new AudioEngine(SampleRate);
    CM = new ClipManager(SampleRate);
    SE = new Sequencer(SampleRate, CM);
}

DAW::~DAW()
{
    delete AE;
    delete CM;
    delete SE;
    
    AE = nullptr;
    CM = nullptr;
    SE = nullptr;
}

void DAW::RunProject(Project* project)
{
    project->Run(AE, CM, SE);
}