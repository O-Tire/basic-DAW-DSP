#define MINIAUDIO_IMPLEMENTATION
#include "libraries/miniaudio.h"

#include <stdio.h>

int main()
{
    ma_result result;
    ma_engine engine;

    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        return -1;
    }

    ma_engine_play_sound(&engine, "D:/Music/Heat.mp3", NULL);

    printf("Press Enter to quit...");
    getchar();

    ma_engine_uninit(&engine);

    return 0;
}