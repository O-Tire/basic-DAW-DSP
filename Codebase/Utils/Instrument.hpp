#pragma once

#include "Constants.hpp"
namespace smf
{
    class MidiEvent;
}
class IEnvelope;
class IVoice;
class DAW;


struct Key
{
    Key(int number);

    int number;
};


/** Can receive MIDI, but requires a voice to play sounds. */
class Instrument
{
private:

    vector<Key> _activeKeys;

    int _sampleRate;

    IVoice* _voice;
    
    IEnvelope* _envelope;
    
    float MidiNoteToFrequency(int key);

public:

    Instrument(DAW* daw, IVoice* voice, IEnvelope* envelope);
    
    void MidiEvent(smf::MidiEvent event, int sampleIdx);

    float Tick(int sampleIndex);
};