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
    
    int SecondsToSamples(float seconds) const;
    
    Clip RenderTrack(const Track track, int numOfSamples);
    
public:

    Sequencer(float sampleRate, ClipManager* cm);
    
    ~Sequencer();
    
    //static Track LoopTrack(const Track& track);

    void AddTrack(Track track);
    
    /** @param seconds How many seconds to render. */
    Clip RenderTracks(float seconds);
};