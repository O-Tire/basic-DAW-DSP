#pragma once

namespace smf
{
    class MidiEvent;
}
class IVoice;


/** Can receive MIDI, but requires a voice to play sounds. */
class Instrument
{
public:

    Instrument(IVoice* voice, int numOfVoices = 3);
    
    ~Instrument();
    
    void SendMidiEvent(smf::MidiEvent event);

    int Tick(int sampleIndex);
};