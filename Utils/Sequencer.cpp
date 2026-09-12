#include "AssetLoader.hpp"
#include "Sequencer.hpp"
#include "Constants.hpp"
#include "Instrument.hpp"
#include "MidiEventList.h"
#include "MidiFile.h"

using namespace smf;


Sequencer::Sequencer(float sampleRate, float tempo, AssetLoader* al)
{
    _sampleRate = sampleRate;
    _tempo = tempo;
    _clipManagerRef = al;
}

Sequencer::~Sequencer()
{
    _clipManagerRef = nullptr;
}

int Sequencer::SecondsToSamples(float seconds) const
{
    return (int)floor(seconds * _sampleRate);
}

Track Sequencer::LoopTrack(const Track& track, int numOfLoops, float loopTime)
{
    Track result;
    
    /*for (int i = 0; i < numOfLoops; i++)
    {
        for (const auto& pair : track)
        {
            result[loopTime * i + pair.first] = pair.second;
        }
    }*/
    return result;
}

void Sequencer::AddTrack(Track track)
{
    _tracks.push_back(track);
}

Clip Sequencer::RenderTrack(const Track track, int samplesToRender)
{
    Clip render(samplesToRender, 0.f);
    int currentEventIdx = 0;
    
    MidiFile& midi          = *track.first;
    Instrument& instrument  = *track.second;
    
    midi.doTimeAnalysis();
    MidiEventList events = midi[0];
    
    
    for (int i = 0; i < samplesToRender; i++)
    {
        while (currentEventIdx < events.size() && SecondsToSamples(events[currentEventIdx].seconds) == i)
        {
            instrument.SendMidiEvent(events[currentEventIdx]);
            currentEventIdx++;
        }
    
        render[i] += instrument.Tick(i);
    }
    
    return render;
}

Clip Sequencer::RenderTracks(float seconds)
{
    int samplesToRender = SecondsToSamples(seconds);
    Clip finalRender(samplesToRender, 0.f);
    vector<Clip> renderedTracks;

    // Render tracks.
    for (Track track : _tracks)
    {
        renderedTracks.push_back(RenderTrack(track, samplesToRender));
    }
    
    // Mix down to a single channel.
    for (int i = 0; i < samplesToRender; i++)
    {
        for (const Clip& clip : renderedTracks)
        {
            finalRender[i] += clip[i];
        }
    }
    
    return finalRender;
}