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
    
    /** @param numOfLoops 2 means loop once. (play twice)
     *  @param loopTime When to insert the loop.
     */
    [[nodiscard]]
    static Track LoopTrack(const Track& track, int numOfLoops, float loopTime);

    void AddTrack(Track track);
    
    /** @param seconds How many seconds to render. */
    Clip RenderTracks(float seconds);
};