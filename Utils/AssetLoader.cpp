#include "AssetLoader.hpp"
#include "Constants.hpp"


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