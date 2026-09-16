#pragma once

#include "IVoice.hpp"
#include <string>

extern "C"
{
    #include "lua.h"
}


class LuaVoice : IVoice
{
private:

    std::string _luaFuncName = "";
    
    lua_State* _luaState_Ref = nullptr;

public:
    
    LuaVoice(lua_State* luaState, const char* luaFunName);

    virtual float GetSample(int sampleIdx, float frequency, int sampleRate) const override;
};