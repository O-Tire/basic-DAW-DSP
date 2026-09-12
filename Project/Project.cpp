#include "Project.hpp"

#include "AudioEngine.hpp"
#include "AssetLoader.hpp"
#include "Instrument.hpp"
#include "Sequencer.hpp"

#include "Synth.hpp"

#include <memory>
using std::make_shared;
using std::make_unique;



void Project::Run(AudioEngine* AE, AssetLoader* AL, Sequencer* SE, DAW* DA)
{
    AL->LoadWAV("D:/temp/kick.wav");
    AL->LoadWAV("D:/temp/hihat.wav");
    AL->LoadMIDI("D:/temp/midi.mid");
    
    auto voice = make_shared<Synth>();
    auto instrument = make_unique<Instrument>(DA, voice);
    
    Track track1 = {AL->MIDIs[0], instrument.get()};
    
    SE->AddTrack(track1);
    Clip samples = SE->RenderTracks(10);
    
    AE->PlaySamples(samples);
}