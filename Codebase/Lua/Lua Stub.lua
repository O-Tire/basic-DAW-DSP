-- @param *path* The location of the file.
--
-- @returns The loaded WAV.
function load_wav(path) end

-- @param *path* The location of the file.
--
-- @returns The loaded MIDI.
function load_midi(path) end

-- Creates a track on the sequencer.
--
-- @param *midi* A loaded MIDI for the instrument to play.
--
-- @param *instrument* The target instrument.
function add_track(midi, instrument) end

-- Renders all the tracks and mixes them into a final signal.
--
-- @param seconds How much of your song to render.
function render_tracks(seconds) end

-- Creates an instrument object which can be used by add_track().
--
-- @param *voice* The sound generator to use.
--
-- @param *envelope* The envelope to use.
--
-- @returns The created instrument.
function make_instrument(voice, envelope) end

-- Creates an ADSR (Attack, Decay, Sustain, Release) envelope.
-- Envelopes are used to make instruments.
--
-- @params *a d s r* Are all numbers.
--
-- @returns The created ADSR envelope.
function make_adsr(a, d, s, r) end

--[[
**Creates a programmable voice. Voices can generate sounds and are used by instruments.**

To make a voice, you first need to create a "Voice Function".
Some information will be passed to this function (like the frequency) and you are expects
to return a sound sample aka just a number.

- This is an example of a Voice Function:
```lua
function Synth(sampleIdx, freq, sampleRate)
   return math.sin(math.pi * 2 * sampleIdx * freq / sampleRate) / 4;
end
```

@param *globalFunctionName* After you wrote a function like the one above, write its name as
this parameter. In this example, that would be "Synth".
]]--
function make_voice_lua(globalFunctionName) end