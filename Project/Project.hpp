#pragma once

class AudioEngine;
class AssetLoader;
class Sequencer;
class DAW;


/** All user instructions will be written to 'Run()'. Used by DAW. */
class Project
{
public:

    /** @param AE AudioEngine.
     *  @param AL AssetLoader.
     *  @param SE Sequencer.
     */
    virtual void Run(AudioEngine* AE, AssetLoader* AL, Sequencer* SE, DAW* DA);
};