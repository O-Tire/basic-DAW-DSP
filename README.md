A very basic DAW running on [MiniAudio](https://github.com/mackron/miniaudio), capable of simple audio playback, sequencing & MIDI playback.

> MIDI is WIP and isn't supported yet.

# Capabilities:
- Asset loader: can load WAV and MIDI files.
- Basic sequencer: able to read MIDI.
- Synthesizer: very flexible because it can be coded to do whatever you want!
- Very light weight and fast.
- Cross-platform.

# Weaknesses:
- Cannot load any audio files except single channel 48000Hz WAV files.
The sample rate can be changed but the amount of channels is hardcoded.
- No realtime playback. The entire project must be rendered before playback begins.
- Needs to be recompiled everytime project code changes.

## How to use:
To get started, open [Project.cpp](Project/Project.cpp) take a look
at the example then start modifying the Run() function.

You can also extend the Synthesizer class and customize it.

To hear your project, you must recompile and Run the executable created in "build/".

## How to compile:

When done modifying the project, make sure you have installed:

1. Any C++ compiler
1. CMake
1. Ninja (or any other build system)
1. PowerShell (optional)

If you have all the above, you can simple run [make.ps1](make.ps1) to compile and hear your project.

But:

- If you are not using Ninja, you must configure [make.ps1](make.ps1) to use your own build system instead.
- If you don't have PowerShell, just change the extension of [make.ps1](make.ps1) and [run.ps1](run.ps1) from .ps1 to .cmd (for Windows) and .sh (for Linux). Alternatively, you can paste the commands directly into your shell of choice.
- If you are using Linux, remove '.exe' from [run.ps1](run.ps1).

---
---
---

### What is this for?:
Not for actual professional audio editing and music production (of course).

Useful for people who like creating synths or manipulating signals/audio with code.

Note that this project was not tested on Linux, but all the C++ code should be cross-platform.