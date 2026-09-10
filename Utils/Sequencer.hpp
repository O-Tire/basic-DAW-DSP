#pragma once

#include <vector>
#include "Constants.hpp"


class Sequencer
{
private:

    std::vector<Track> Tracks;
    
public:

    void AddTrack(Track track);
    
    Clip RenderTracks(float seconds);
};