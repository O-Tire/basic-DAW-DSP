#pragma once

class AudioEngine;
class ClipManager;


/** All user instructions will be written to 'Run()'. Used by DAW. */
class Project
{
public:

    /** @param AE AudioEngine.
     *  @param CM ClipManager.
     */
    void Run(AudioEngine* AE, ClipManager* CM);
};