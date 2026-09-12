#include "Instrument.hpp"
#include "MidiEvent.h"
#include "IVoice.hpp"
#include "DAW.hpp"
#include <cstdio>


Instrument::Instrument(DAW* daw, IVoice* voice)
{
    _voice = voice;
    _sampleRate = daw->SampleRate;
}

void Instrument::SendMidiEvent(smf::MidiEvent event)
{
    // TODO: WIP
    printf("%b", event.isNoteOn());
}

float Instrument::Tick(int sampleIdx)
{
    // TODO: WIP
    return _voice->GetSample(sampleIdx, 440.f, _sampleRate);
}