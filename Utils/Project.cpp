#include "Project.hpp"
#include "AudioEngine.hpp"
#include "ClipManager.hpp"
#include "Sequencer.hpp"
//#include "Synth.hpp" // Also available


void Project::Run(AudioEngine* AE, ClipManager* CM, Sequencer* SE)
{
    CM->LoadClip("D:/temp/kick.wav");
    CM->LoadClip("D:/temp/hihat.wav");
    
    Track track1 = {
        {0.f, 0},
        {.25f, 1},
        
        {.5f, 0},
        {.75f, 1},
        
        {1.f, 0},
        {1.25f, 1},
        
        {1.5f, 0},
        {1.75f, 1},
    };
    
    SE->AddTrack(track1);
    Clip samples = SE->RenderTracks(10);
    
    AE->PlaySamples(samples);
}