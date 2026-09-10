#include "ClipManager.hpp"
#include "Sequencer.hpp"
#include "Constants.hpp"


Sequencer::Sequencer(float sampleRate, ClipManager* cm)
{
    _sampleRate = sampleRate;
    _clipManagerRef = cm;
}

Sequencer::~Sequencer()
{
    _clipManagerRef = nullptr;
}

int Sequencer::SecondsToSamples(float seconds) const
{
    return (int)floor(seconds * _sampleRate);
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
    std::vector<Clip> renderedTracks;

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