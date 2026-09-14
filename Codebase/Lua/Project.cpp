#include "Project.hpp"

#include "AudioEngine.hpp"
#include "AssetLoader.hpp"
#include "Instrument.hpp"
#include "Sequencer.hpp"

#include <cstdio>

extern "C"
{
    #include "lua.h"
    #include "lauxlib.h"
    #include "lualib.h"
}


void Project::Run(AudioEngine* AE, AssetLoader* AL, Sequencer* SE, DAW* DA, std::string path)
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    
    //------------- Execute script.
    
    int fileResult = luaL_dofile(L, path.c_str());
    
    if (fileResult != LUA_OK)
    {
        printf("Could not open the .lua file.\n%s\n", lua_tostring(L, -1));
    }
    
    lua_close(L);
}