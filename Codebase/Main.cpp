#define MINIAUDIO_IMPLEMENTATION
#define DR_WAV_IMPLEMENTATION

#include "DAW.hpp"
#include "Project.hpp"
#include <cstdio>

int main(int argc, char* argv[])
{
    // Parse CL arguments.
    
    if (argc != 2)
    {
        printf("Please pass the path of your .lua file as an argument.\nDAW couldn't initialize.\n");
        return -1;
    }
    
    // Initialize DAW.

    DAW daw;
    
    daw.RunProject(argv[1]);
    
    printf("Playing. Press any key to exit...\n");
    getchar(); // wait until user presses Enter
    
    return 0;
}