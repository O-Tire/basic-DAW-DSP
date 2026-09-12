#include "Instrument.hpp"
#include "MidiEvent.h"
#include "IVoice.hpp"
#include "DAW.hpp"
#include <cstdio>


Instrument::Instrument(DAW* daw, shared_ptr<IVoice> voice)
{
    _voice = voice;
    _daw_Ref = daw;
}

void Instrument::SendMidiEvent(smf::MidiEvent event)
{
    // TODO: WIP
    printf("%b", event.isNoteOn());
}

float Instrument::Tick(int sampleIdx)
{
    // TODO: WIP
    return _voice->GetSample(sampleIdx, 440.f, _daw_Ref->SampleRate);
}