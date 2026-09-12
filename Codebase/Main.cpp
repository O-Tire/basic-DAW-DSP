#define MINIAUDIO_IMPLEMENTATION
#define DR_WAV_IMPLEMENTATION

#include "DAW.hpp"
#include "Project.hpp"
#include <iostream>

int main()
{
    DAW daw;
    MyProject project;
    
    daw.RunProject(&project);
    
    std::cout << "Playing. Press any key to exit...\n";
    getchar(); // wait until user presses Enter
    
    return 0;
}