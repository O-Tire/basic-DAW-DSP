#include "AssetLoader.hpp"
#include "Constants.hpp"
#include "MidiFile.h"


AssetLoader::AssetLoader(float sampleRate)
{
    _sampleRate = sampleRate;
}

void AssetLoader::LoadWAV(const char* path)
{
    drwav wav;
    drwav_init_file(&wav, path, nullptr);
    
    Clip clip(wav.totalPCMFrameCount);
    drwav_read_pcm_frames_f32(&wav, wav.totalPCMFrameCount, clip.data());
    
    drwav_uninit(&wav);
    Clips.push_back(clip);
}

void AssetLoader::LoadMIDI(const char* path)
{
    smf::MidiFile* midi = new smf::MidiFile(path);
    
    MIDIs.push_back(midi);
}