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


typedef vector<float> Clip;

/** Clip start time to clip index. */
typedef std::pair<smf::MidiFile*, Instrument*> Track;