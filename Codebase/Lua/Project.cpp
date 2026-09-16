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

// Paste in Glue CPPs.
#include "AssetLoader_Glue.cpp"

void Project::Run(AudioEngine* AE, AssetLoader* AL, Sequencer* SE, DAW* DA, std::string path)
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    
    //------------- Register.
    
    // LoadWAV()
    lua_pushlightuserdata(L, AL);
    lua_pushcclosure(L, LoadWAV_lua, 1);
    lua_setglobal(L, "load_wav");
    
    // LoadMIDI()
    lua_pushlightuserdata(L, AL);
    lua_pushcclosure(L, LoadMIDI_lua, 1);
    lua_setglobal(L, "load_midi");
    
    //------------- Execute script.
    
    int fileResult = luaL_dofile(L, path.c_str());
    
    if (fileResult != LUA_OK)
    {
        printf("Could not open the .lua file.\n%s\n", lua_tostring(L, -1));
    }
    
    lua_close(L);
}