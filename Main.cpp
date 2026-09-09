#define MINIAUDIO_IMPLEMENTATION
#include "Utils/AudioEngine.hpp"
#include <iostream>
#include "utils/synth.hpp"


int main()
{
    float sampleRate = 44100.f;

    SampleList samples = Synth::Synthesize(440, 10, sampleRate);
    AudioEngine AE(sampleRate);

    AE.PlaySamples(samples);
    
    std::cout << "Playing sine wave...\n";
    getchar(); // wait until user presses Enter
    
    
    return 0;
}