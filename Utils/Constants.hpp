#pragma once

#include <map>
#include <vector>


#define SAMPLE_RATE 48000.f

typedef std::vector<float> Clip;

/** Clip start time to clip index. */
typedef std::map<float, int> Track;