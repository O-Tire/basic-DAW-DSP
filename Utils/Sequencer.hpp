#pragma once

#include <vector>
#include "Constants.hpp"

class ClipManager;


class Sequencer
{
private:

    float _sampleRate;
    
    ClipManager* _clipManagerRef;

    std::vector<Track> _tracks;
    
    int SecondsToSamples(float seconds);
    
    Clip RenderTrack(Track track, int numOfSamples);
    
public:

    Sequencer(float sampleRate, ClipManager* cm);
    
    ~Sequencer();

    void AddTrack(Track track);
    
    /** @param seconds How many seconds to render. */
    Clip RenderTracks(float seconds);
};