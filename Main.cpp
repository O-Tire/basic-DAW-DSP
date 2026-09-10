#define MINIAUDIO_IMPLEMENTATION
#define DR_WAV_IMPLEMENTATION

#include "Utils/ClipManager.hpp"
#include "Utils/AudioEngine.hpp"
#include <iostream>

int main()
{
    float sampleRate = 48000.f;
    
    ClipManager CM(sampleRate);
    AudioEngine AE(sampleRate);
    
    CM.LoadClip("D:/temp/.wav");
    AE.PlaySamples(CM.Clips[0]);
    
    std::cout << "Playing...\n";
    getchar(); // wait until user presses Enter
    
    
    return 0;
}