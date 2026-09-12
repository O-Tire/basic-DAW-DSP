#pragma once

namespace smf
{
    class MidiEvent;
}
class IVoice;
class DAW;


/** Can receive MIDI, but requires a voice to play sounds. */
class Instrument
{
private:

    int _sampleRate;

    IVoice* _voice;

public:

    Instrument(DAW* daw, IVoice* voice);
    
    void SendMidiEvent(smf::MidiEvent event);

    float Tick(int sampleIndex);
};