
#include "Constants.hpp"
#include "DAW.hpp"
#include "IEnvelope.hpp"
#include "IVoice.hpp"
#include "Instrument.hpp"
#include "Synth.hpp"

extern "C"
{
    #include "lua.h"
    #include "lauxlib.h"
}

static int MakeInstrument_lua(lua_State* L)
{
    DAW* DA = static_cast<DAW*>(lua_touserdata(L, lua_upvalueindex(1))); // Closure
    
    //IVoice* voice = static_cast<IVoice*>(luaL_checkudata(L, 1, Lua::VOICE_META)); // Arg 1
    IEnvelope* envelope = static_cast<IEnvelope*>(luaL_checkudata(L, 2, Lua::ENVELOPE_META)); // Arg 2
    
    IVoice* voice = new Synth();
    
    Instrument* instrument = reinterpret_cast<Instrument*>(lua_newuserdata(L, sizeof(Instrument)));
    new(instrument) Instrument(DA, voice, envelope);
    
    luaL_setmetatable(L, Lua::INSTRUMENT_META);
    return 1;
}

static int DestroyInstrument_lua(lua_State* L)
{
    Instrument* self = static_cast<Instrument*>(luaL_checkudata(L, 1, Lua::INSTRUMENT_META)); // Arg 1
    
    self->~Instrument();
    return 0;
}

static void RegisterInstrument(lua_State* L)
{
    luaL_newmetatable(L, Lua::INSTRUMENT_META);
    
    lua_pushvalue(L, -1); // Duplicate metatable.
    lua_setfield(L, -2, "__index");
    
    lua_pushcfunction(L, DestroyInstrument_lua);
    lua_setfield(L, -2, "__gc");
}