#pragma once

#include "Constants.hpp"
namespace smf
{
    class MidiEvent;
}
class IVoice;
class DAW;


struct Key
{
    Key(int number, int sampleIdx);

    int number;
    
    /** The sample index at which the key was pressed. */
    int sampleIdx;
};


/** Can receive MIDI, but requires a voice to play sounds. */
class Instrument
{
private:

    vector<Key> _activeKeys;

    int _sampleRate;
    
    int _currentSample = 0;

    IVoice* _voice;
    
    float MidiNoteToFrequency(int key);

public:

    Instrument(DAW* daw, IVoice* voice);
    
    void MidiEvent(smf::MidiEvent event);

    float Tick(int sampleIndex);
};