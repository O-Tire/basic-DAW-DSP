

#include "ADSR.hpp"
#include "Constants.hpp"

extern "C"
{
    #include "lua.h"
    #include "lauxlib.h"
}

static int MakeADSR_lua(lua_State* L)
{
    float a = luaL_checknumber(L, 1); // Arg 1
    float d = luaL_checknumber(L, 2); // Arg 2
    float s = luaL_checknumber(L, 3); // Arg 3
    float r = luaL_checknumber(L, 4); // Arg 4
    
    ADSR* adsr = reinterpret_cast<ADSR*>(lua_newuserdata(L, sizeof(ADSR)));
    new(adsr) ADSR(a, d, s, r);
    
    luaL_setmetatable(L, Lua::ENVELOPE_META);
    return 1;
}

static int DestroyADSR_lua(lua_State* L)
{
    ADSR* self = static_cast<ADSR*>(luaL_checkudata(L, 1, Lua::ENVELOPE_META)); // Arg 1

    self->~ADSR();
    return 0;
}

static void RegisterADSR(lua_State* L)
{
    luaL_newmetatable(L, Lua::ENVELOPE_META);
    
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");
    
    lua_pushcfunction(L, DestroyADSR_lua);
    lua_setglobal(L, "__gc");
}