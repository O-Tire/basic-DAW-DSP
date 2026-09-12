#pragma once

#include "Constants.hpp"

namespace smf
{
    class MidiEvent;
}
class AssetLoader;


class Sequencer
{
private:

    float _sampleRate;
    
    float _tempo;
    
    AssetLoader* _clipManagerRef;

    vector<Track> _tracks;
    
    int SecondsToSamples(float seconds) const;
    
    Clip RenderTrack(const Track track, int samplesToRender);
    
public:

    Sequencer(float sampleRate, float tempo, AssetLoader* al);
    
    ~Sequencer();
    
    /** @param numOfLoops 2 means loop once. (play twice)
     *  @param loopTime When to insert the loop.
     */
    [[nodiscard]]
    static Track LoopTrack(const Track& track, int numOfLoops, float loopTime); // TODO

    void AddTrack(Track track);
    
    /** @param seconds How many seconds to render. */
    Clip RenderTracks(float seconds);
};