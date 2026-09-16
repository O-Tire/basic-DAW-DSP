An simple DAW that lets you program you synths in (arguably) the world's easiest and (objectively) the best programming language, Lua!

# Capabilities:
- Easy to use and master.
- Generate sounds using code.
- Light weight and fast.
- Asset loader: can load WAV and MIDI files.
- Basic sequencer: able to read MIDI.
- Synthesizer: very flexible.
- Cross-platform. (but only Windows binaries included)

# Limitations:
- Cannot load any audio files except single channel 48000Hz WAV files.
The sample rate can be changed but the amount of channels cannot.
- No realtime playback. The entire project must be rendered before playback begins.

## Code Editor Setup:
1. It is recommended that you use a code editor with a Lua language server extension. (for syntax highlighting and auto-completion)

> But it is not required; you can also read the [Lua Stub](Codebase/Lua/Lua%20Stub.lua) file, since it's both a stub and a documentation.

2. Make sure your language server can read the [Lua Stub](Codebase/Lua/Lua%20Stub.lua) file.

## How to use.
1. Download the binaries, or compile the project yourself.
1. Like in the example, write your Lua code and save it to a file.
1. Pass that file as the first argument of the DAW. (you can also drag and drop your Lua file on the executable)

That's it.

## Example:
```lua
require("math")

function Synth(sampleIdx, freq, sampleRate)
    return math.sin(math.pi * 2 * sampleIdx * freq / sampleRate) / 4;
end

local midi = load_midi("C:/folder/midi.mid")
local voice = make_voice_lua("Synth");
local envelope = make_adsr(.05,.2, 0, 0);
local instrument = make_instrument(voice, envelope)

add_track(midi, instrument)
render_tracks(10)
```
Then run the program with your Lua file as the argument.

You can also drag the Lua file on the executable to run it. (on Windows)

## How to compile:

1. Any C++ compiler
1. CMake
1. Ninja (*or any other build system)
1. PowerShell (*optional)

If you have all the above, you can simply run [make.ps1](make.ps1) to compile.

But:

- If you are not using Ninja, you must configure [make.ps1](make.ps1) to use your own build system instead.
- If you don't have PowerShell, just change the extension of [`make.ps1`](make.ps1) and [`run.ps1`](run.ps1) from `.ps1` to `.cmd` (for Windows) and `.sh` (for Linux). Alternatively, you can paste the commands directly into your shell of choice.
- If you are using Linux, remove `.exe` from [run.ps1](run.ps1).
- On Linux, configure CMake to use `liblua55.a` instead of `lua55.lib`.

---
---
---

### Who is this for?:
For people who like creating synths or manipulating signals/audio with code.

Note that this project was only tested on Windows, but all the C++ code should be cross-platform.