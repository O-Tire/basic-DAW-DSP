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
    // TODO
}

Clip Sequencer::RenderTracks(float seconds)
{
    int numOfSamples = SecondsToSamples(seconds);
    Clip finalRender(numOfSamples);
    std::vector<Clip> renderedTracks;

    // Render tracks.
    for (Track track : _tracks)
    {
        renderedTracks.push_back(RenderTrack(track, numOfSamples));
    }
    
    // Mix down to a single channel.
    for (int i = 0; i < numOfSamples; i++)
    {
        for (Clip clip : renderedTracks)
        {
            finalRender[i] += clip[i];
        }
    }
    
    return finalRender;
}