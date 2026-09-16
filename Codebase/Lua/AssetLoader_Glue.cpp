#include "AssetLoader.hpp"

extern "C"
{
    #include "lua.h"
    #include "lauxlib.h"
}

static int LoadWAV_lua(lua_State* L)
{
    AssetLoader* AL = static_cast<AssetLoader*>(lua_touserdata(L, lua_upvalueindex(1)));
    const char* path = luaL_checkstring(L, 1); // Arg 1
    
    AL->LoadWAV(path);
    
    lua_pushinteger(L, AL->Clips.size() - 1);
    return 1;
}

static int LoadMIDI_lua(lua_State* L)
{
    AssetLoader* AL = static_cast<AssetLoader*>(lua_touserdata(L, lua_upvalueindex(1)));
    const char* path = luaL_checkstring(L, 1); // Arg 1
    
    AL->LoadMIDI(path);
    
    lua_pushinteger(L, AL->MIDIs.size() - 1);
    return 1;
}