#pragma once

#include "dr_wav.h"
#include "Constants.hpp"

namespace smf
{
    class MidiFile;
}


/** Loades assets such as WAV audio files or MIDI. */
class AssetLoader
{
private:

    float _sampleRate;

public:

    vector<Clip> Clips;
    
    vector<smf::MidiFile*> MIDIs;
    
    AssetLoader(float sampleRate);

    /** Loads WAV files and turns them into samples and pushes them to 'Clips'. */
    void LoadWAV(const char* path);
    
    /** Loads MIDI files and pushes them to 'MIDIs'. */
    void LoadMIDI(const char* path);
};