#include "Constants.hpp"
#include "LuaVoice.hpp"

extern "C"
{
    #include "lua.h"
    #include "lauxlib.h"
}


static int MakeLuaVoice_lua(lua_State* L)
{
    const char* luaFuncName = luaL_checkstring(L, 1); // Arg 1

    LuaVoice* MakeVoice_lua = reinterpret_cast<LuaVoice*>(lua_newuserdata(L, sizeof(LuaVoice)));
    new(MakeVoice_lua) LuaVoice(L, luaFuncName);
    
    luaL_setmetatable(L, Lua::LUA_VOICE_META);
    return 1;
}

static int DestroyLuaVoice_lua(lua_State* L)
{
    LuaVoice* self = static_cast<LuaVoice*>(luaL_checkudata(L, 1, Lua::LUA_VOICE_META)); // Arg 1
    
    self->~LuaVoice();
    return 0;
}

static void RegisterLuaVoice(lua_State* L)
{
    luaL_newmetatable(L, Lua::LUA_VOICE_META);
    
    lua_pushvalue(L, -1); // Duplicate metatable.
    lua_setfield(L, -2, "__index");
    
    lua_pushcfunction(L, DestroyLuaVoice_lua);
    lua_setfield(L, -2, "__gc");
}