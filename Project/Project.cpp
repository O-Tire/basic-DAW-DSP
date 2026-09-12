#include "Project.hpp"
#include "AudioEngine.hpp"
#include "AssetLoader.hpp"
#include "Sequencer.hpp"
//#include "Synth.hpp" // Also available


void Project::Run(AudioEngine* AE, AssetLoader* AL, Sequencer* SE)
{
    AL->LoadWAV("D:/temp/kick.wav");
    AL->LoadWAV("D:/temp/hihat.wav");
    AL->LoadMIDI("D:/temp/midi.mid");
    
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
    
    track1 = SE->LoopTrack(track1, 4, 2.f);
    SE->AddTrack(track1);
    Clip samples = SE->RenderTracks(10);
    
    AE->PlaySamples(samples);
}