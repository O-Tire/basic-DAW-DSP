#include "Project.hpp"
#include "AudioEngine.hpp"
#include "ClipManager.hpp"


void Project::Run(AudioEngine* AE, ClipManager* CM)
{
    CM->LoadClip("D:/temp/.wav");
    AE->PlaySamples(CM->Clips[0]);
}