#pragma once

#include "IProject.hpp"

class AudioEngine;
class AssetLoader;
class Sequencer;
class DAW;


/** All user instructions will be written to 'Run()'. Used by DAW. */
class MyProject : public IProject
{
public:

    virtual void Run(AudioEngine* AE, AssetLoader* AL, Sequencer* SE, DAW* DA) override;
};