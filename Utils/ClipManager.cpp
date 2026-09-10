#include "ClipManager.hpp"
#include "Constants.hpp"


ClipManager::ClipManager(float sampleRate)
{
    _sampleRate = sampleRate;
}

void ClipManager::LoadClip(const char* path)
{
    drwav wav;
    drwav_init_file(&wav, path, nullptr);
    
    SampleList clip(wav.totalPCMFrameCount);
    drwav_read_pcm_frames_f32(&wav, wav.totalPCMFrameCount, clip.data());
    
    Clips.push_back(clip);
}