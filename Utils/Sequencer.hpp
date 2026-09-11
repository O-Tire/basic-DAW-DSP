#pragma once

#include "Constants.hpp"

class AssetLoader;


class Sequencer
{
private:

    float _sampleRate;
    
    AssetLoader* _clipManagerRef;

    vector<Track> _tracks;
    
    int SecondsToSamples(float seconds) const;
    
    Clip RenderTrack(const Track track, int numOfSamples);
    
public:

    Sequencer(float sampleRate, AssetLoader* al);
    
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