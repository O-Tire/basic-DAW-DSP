#include "Project.hpp"
#include "AudioEngine.hpp"
#include "ClipManager.hpp"
#include "Sequencer.hpp"
//#include "Synth.hpp" // Also available


void Project::Run(AudioEngine* AE, ClipManager* CM, Sequencer* SE)
{
    CM->LoadClip("D:/temp/.wav");
    
    Track track1 = {{0.f, 0}};
    SE->AddTrack(track1);
    Clip samples = SE->RenderTracks(10);
    
    AE->PlaySamples(samples);
}