#pragma once

namespace smf
{
    class MidiEvent;
}
class IVoice;


/** Can receive MIDI, but requires a voice to play sounds. */
class Instrument
{
private:

    IVoice* _voice = nullptr;

public:

    Instrument(IVoice* voice);
    
    ~Instrument();
    
    void SendMidiEvent(smf::MidiEvent event);

    float Tick(int sampleIndex);
};