#include "DAW.hpp"
#include "AudioEngine.hpp"
#include "AssetLoader.hpp"
#include "Project.hpp"
#include "Sequencer.hpp"


DAW::DAW()
{
    AE = new AudioEngine(SampleRate);
    AL = new AssetLoader(SampleRate);
    SE = new Sequencer(SampleRate, Tempo, AL);
}

DAW::~DAW()
{
    delete AE;
    delete AL;
    delete SE;
    
    AE = nullptr;
    AL = nullptr;
    SE = nullptr;
}

void DAW::RunProject(Project* project)
{
    project->Run(AE, AL, SE);
}