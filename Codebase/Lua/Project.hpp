#pragma once

class AudioEngine;
class AssetLoader;
class Sequencer;
class DAW;


/** Loads the Lua files/project that user has made. */
class Project
{
public:

    void Run(AudioEngine* AE, AssetLoader* AL, Sequencer* SE, DAW* DA);
};