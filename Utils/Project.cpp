#include "Project.hpp"
#include "AudioEngine.hpp"
#include "ClipManager.hpp"


void Project::Run(AudioEngine* AE, ClipManager* CM, Sequencer* SE)
{
    CM->LoadClip("D:/temp/.wav");
    AE->PlaySamples(CM->Clips[0]);
}