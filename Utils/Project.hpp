#pragma once

class AudioEngine;
class ClipManager;
class Sequencer;


/** All user instructions will be written to 'Run()'. Used by DAW. */
class Project
{
public:

    /** @param AE AudioEngine.
     *  @param CM ClipManager.
     *  @param SE Sequencer.
     */
    void Run(AudioEngine* AE, ClipManager* CM, Sequencer* SE);
};