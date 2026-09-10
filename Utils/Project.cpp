#include "Project.hpp"
#include "AudioEngine.hpp"
#include "ClipManager.hpp"
#include "Sequencer.hpp"


void Project::Run(AudioEngine* AE, ClipManager* CM, Sequencer* SE)
{
    CM->LoadClip("D:/temp/.wav");
    
    Track track1 = {{1.f, 0}};
    SE->AddTrack(track1);
    Clip samples = SE->RenderTracks(10);
    
    AE->PlaySamples(samples);
}