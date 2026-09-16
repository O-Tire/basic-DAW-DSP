#include "AssetLoader.hpp"
#include "AudioEngine.hpp"
#include "Constants.hpp"
#include "Instrument.hpp"
#include "Sequencer.hpp"

extern "C"
{
    #include "lua.h"
    #include "lauxlib.h"
}

static int AddTrack_lua(lua_State* L)
{
    Sequencer* SE = static_cast<Sequencer*>(lua_touserdata(L, lua_upvalueindex(1)));
    AssetLoader* AL = static_cast<AssetLoader*>(lua_touserdata(L, lua_upvalueindex(2)));
    
    int idxOfMidi = luaL_checkinteger(L, 1); // Arg 1
    Instrument* instrument = static_cast<Instrument*>(luaL_checkudata(L, 2, "InstrumentMeta")); // Arg 2
    
    SE->AddTrack(Track(AL->MIDIs[idxOfMidi], instrument));
    return 0;
}

static int RenderTracks_lua(lua_State* L) // TODO: Move out AudioEngine functionality.
{
    Sequencer* SE = static_cast<Sequencer*>(lua_touserdata(L, lua_upvalueindex(1)));
    AudioEngine* AE = static_cast<AudioEngine*>(lua_touserdata(L, lua_upvalueindex(2)));
    
    float seconds = luaL_checknumber(L, 1); // Arg 1
    
    AE->PlaySamples(SE->RenderTracks(seconds));
    return 0;
}