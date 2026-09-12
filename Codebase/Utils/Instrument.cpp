#include "Instrument.hpp"
#include "MidiEvent.h"
#include "IVoice.hpp"
#include "DAW.hpp"


Key::Key(int number, int sampleIdx)
{
    this->number    = number;
    this->sampleIdx = sampleIdx;
}

Instrument::Instrument(DAW* daw, IVoice* voice)
{
    _voice      = voice;
    _sampleRate = daw->SampleRate;
}

float Instrument::MidiNoteToFrequency(int key)
{
    return 440.0 * pow(2.0, (key - 69) / 12.0);
}

void Instrument::MidiEvent(smf::MidiEvent event)
{
    if (event.isNoteOn())
    {
        // Start note.
        _activeKeys.push_back(Key(event.getKeyNumber(), _currentSample));
    }
    else
    if (event.isNoteOff())
    {
        // End note.
        for (int i = 0; i < _activeKeys.size(); i++)
        {
            if (event.getKeyNumber() != _activeKeys[i].number) continue;
            
            _activeKeys.erase(_activeKeys.begin() + i);
            break;
        }
    }
}

float Instrument::Tick(int sampleIdx)
{
    _currentSample = sampleIdx;
    
    for (auto key : _activeKeys)
    {
        return _voice->GetSample(sampleIdx, MidiNoteToFrequency(key.number), _sampleRate);
    }
    return 0.f;
}