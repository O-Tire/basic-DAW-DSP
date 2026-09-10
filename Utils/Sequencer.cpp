#include "Sequencer.hpp"

void Sequencer::AddTrack(Track track)
{
    Tracks.push_back(track);
}

Clip Sequencer::RenderTracks(float seconds)
{
    // TODO
}