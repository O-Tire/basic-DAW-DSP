#pragma once

#include <map>
#include <vector>
using std::vector;
using  std::map;

namespace smf
{
    class MidiFile;
}
class Instrument;

//---------------------------------------------------- Actual content:

namespace Lua
{
    constexpr const char* INSTRUMENT_META = "Instrument";
    constexpr const char* LUA_VOICE_META      = "LuaVoice";
    constexpr const char* ENVELOPE_META   = "Envelope";
}

typedef vector<float> Clip;

/** Clip start time to clip index. */
typedef std::pair<smf::MidiFile*, Instrument*> Track;

int SecondsToSamples(float seconds, float sampleRate);