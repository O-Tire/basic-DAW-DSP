#include "Project.hpp"

#include "ADSR.hpp"
#include "AudioEngine.hpp"
#include "AssetLoader.hpp"
#include "Instrument.hpp"
#include "Sequencer.hpp"

#include "Synth.hpp"


void MyProject::Run(AudioEngine* AE, AssetLoader* AL, Sequencer* SE, DAW* DA)
{
    AL->LoadWAV("D:/temp/kick.wav");
    AL->LoadWAV("D:/temp/hihat.wav");
    AL->LoadMIDI("D:/temp/midi.mid");
    
    auto voice = new Synth();
    auto envelope = new ADSR(.1, 0.1, 0, 0);
    auto instrument = new Instrument(DA, voice, envelope);
    
    Track track1 = {AL->MIDIs[0], instrument};
    
    SE->AddTrack(track1);
    Clip samples = SE->RenderTracks(10);
    
    AE->PlaySamples(samples);
}