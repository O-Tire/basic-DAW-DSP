#include "LuaVoice.hpp"
#include "lua.h"


LuaVoice::LuaVoice(lua_State* luaState, const char* luaFunName)
{
    _luaState_Ref = luaState;
    _luaFuncName = luaFunName;
}

float LuaVoice::GetSample(int sampleIdx, float frequency, int sampleRate) const
{
    lua_getglobal(_luaState_Ref, _luaFuncName.c_str());
    
    lua_pushinteger(_luaState_Ref, sampleIdx); // Arg 1
    lua_pushnumber(_luaState_Ref, frequency); // Arg 2
    lua_pushinteger(_luaState_Ref, sampleRate); // Arg 3
    
    lua_pcall(_luaState_Ref, 3, 1, 0);
    
    return lua_tonumber(_luaState_Ref, -1);
}