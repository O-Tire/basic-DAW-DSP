#include "Instrument.hpp"
#include "MidiEvent.h"
#include "IVoice.hpp"
#include "DAW.hpp"
#include "IEnvelope.hpp"


Key::Key(int number, int frameOfAttack)
{
    Number              = number;
    FrameOfAttack       = frameOfAttack;
    HasBeenReleased     = false;
    FrameOfRelease      = 0;
}

void Key::Unrelease(int frameOfRelease)
{
    HasBeenReleased     = true;
    FrameOfRelease      = frameOfRelease;
}

Instrument::Instrument(DAW* daw, IVoice* voice, IEnvelope* envelope)
{
    _sampleRate         = daw->SampleRate;
    _voice              = voice;
    _envelope           = envelope;
}

float Instrument::MidiNoteToFrequency(int key)
{
    return 440.0 * pow(2.0, (key - 69) / 12.0);
}

void Instrument::MidiEvent(smf::MidiEvent event, int sampleIdx)
{
    if (event.isNoteOn())
    {
        // Start note.
        _activeKeys.push_back(Key(event.getKeyNumber(), sampleIdx));
    }
    else
    if (event.isNoteOff())
    {
        // End note.
        for (int i = 0; i < _activeKeys.size(); i++)
        {
            if (event.getKeyNumber() != _activeKeys[i].Number) continue;
            
            _activeKeys[i].Unrelease(sampleIdx);
            break;
        }
    }
}

float Instrument::Tick(int sampleIdx)
{
    float result = 0.f;
    
    // Extract audio from each active voice.
    for (auto key_it = _activeKeys.begin(); key_it != _activeKeys.end(); )
    {
        float sinceAttack   = (float)(sampleIdx - key_it->FrameOfAttack) / _sampleRate;
        float sinceRelease  = (float)(sampleIdx - key_it->FrameOfRelease) / _sampleRate * key_it->HasBeenReleased;
    
        if (_envelope->HasEnded(sinceRelease))
        {
            key_it = _activeKeys.erase(key_it);
            continue;
        }
            
        float envelopeValue = _envelope->GetValue(sinceAttack, sinceRelease);
        float voiceSample   = _voice->GetSample(sampleIdx, MidiNoteToFrequency(key_it->Number), _sampleRate);
        
        result += voiceSample * envelopeValue;
        
        ++key_it;
    }
    
    return result;
}