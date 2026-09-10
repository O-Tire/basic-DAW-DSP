#pragma once

class AudioEngine;
class ClipManager;


class Project
{
public:

    /** @param AE AudioEngine.
     *  @param CM ClipManager.
     */
    void Run(AudioEngine* AE, ClipManager* CM);
};