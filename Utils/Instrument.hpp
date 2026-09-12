#pragma once
#include <memory>
using std::shared_ptr;

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

    shared_ptr<IVoice> _voice;

public:

    Instrument(DAW* daw, shared_ptr<IVoice> voice);
    
    void SendMidiEvent(smf::MidiEvent event);

    float Tick(int sampleIndex);
};