#include "AssetLoader.hpp"
#include "Sequencer.hpp"
#include "Constants.hpp"
#include <utility>


Sequencer::Sequencer(float sampleRate, AssetLoader* al)
{
    _sampleRate = sampleRate;
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
    
    for (int i = 0; i < numOfLoops; i++)
    {
        for (const auto& pair : track)
        {
            result[loopTime * i + pair.first] = pair.second;
        }
    }
    
    return result;
}

void Sequencer::AddTrack(Track track)
{
    _tracks.push_back(track);
}

Clip Sequencer::RenderTrack(const Track track, int numOfSamples)
{
    Clip render(numOfSamples, 0.f);
    
    for (const auto& pair : track)
    {
        const Clip& clip = _clipManagerRef->Clips[pair.second];
        int start = SecondsToSamples(pair.first);
        int end = std::min(numOfSamples, start + (int)clip.size());
        
        for (int i = start; i < end; i++)
        {
            render[i] += clip[i - start];
        }
    }
    
    return render;
}

Clip Sequencer::RenderTracks(float seconds)
{
    int numOfSamples = SecondsToSamples(seconds);
    Clip finalRender(numOfSamples, 0.f);
    vector<Clip> renderedTracks;

    // Render tracks.
    for (Track track : _tracks)
    {
        renderedTracks.push_back(RenderTrack(track, numOfSamples));
    }
    
    // Mix down to a single channel.
    for (int i = 0; i < numOfSamples; i++)
    {
        for (const Clip& clip : renderedTracks)
        {
            finalRender[i] += clip[i];
        }
    }
    
    return finalRender;
}