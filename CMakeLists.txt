cmake_minimum_required(VERSION 3.3)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(DAW)

add_executable(DAW 
Codebase/Main.cpp
Codebase/Utils/AudioEngine.cpp
Codebase/Utils/AssetLoader.cpp
Codebase/Utils/DAW.cpp
Codebase/Utils/Sequencer.cpp
Codebase/Utils/Instrument.cpp
Codebase/Utils/ADSR.cpp
Codebase/Other/Constants.cpp
Codebase/Lua/Project.cpp
"Codebase/Lua/Lua-Only Classes/LuaVoice.cpp"
Custom/Synth.cpp

Libraries/midifile/src/Binasc.cpp
Libraries/midifile/src/MidiEvent.cpp
Libraries/midifile/src/MidiEventList.cpp
Libraries/midifile/src/MidiFile.cpp
Libraries/midifile/src/MidiMessage.cpp
Libraries/midifile/src/Options.cpp
)

target_include_directories(DAW
PRIVATE Codebase/Utils
PRIVATE Codebase/Interfaces
PRIVATE Codebase/Other
PRIVATE Codebase/Lua
PRIVATE "Codebase/Lua/Lua-Only Classes"
PRIVATE Custom

PUBLIC Libraries
PUBLIC Libraries/midifile/include
PUBLIC Libraries/lua/include
)

target_link_libraries(DAW
PRIVATE ${CMAKE_SOURCE_DIR}/Libraries/lua/lua55.lib # Change to liblua55.a for Linux.
)