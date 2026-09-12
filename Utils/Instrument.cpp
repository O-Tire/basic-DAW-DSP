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

float Instrument::MidiNoteToFrequency(int key)
{
    return 440.0 * pow(2.0, (key - 69) / 12.0);
}

void Instrument::MidiEvent(smf::MidiEvent event)
{
    if (event.isNoteOn())
        printf("Key: %i \n", event.getKeyNumber());
    // TODO: WIP
    for (auto key : _activeKeys)
    {
        //if (event.)
    }
}

float Instrument::Tick(int sampleIdx)
{
    // TODO: WIP
    return _voice->GetSample(sampleIdx, 440.f, _sampleRate);
}