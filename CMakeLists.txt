cmake_minimum_required(VERSION 3.3)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(App)

add_executable(App 
Main.cpp
Utils/Synth.cpp
Utils/AudioEngine.cpp
Utils/AssetLoader.cpp
Utils/DAW.cpp
Utils/Sequencer.cpp
Utils/Instrument.cpp
Project/Project.cpp
Interfaces/IVoice.cpp

Libraries/midifile/src/Binasc.cpp
Libraries/midifile/src/MidiEvent.cpp
Libraries/midifile/src/MidiEventList.cpp
Libraries/midifile/src/MidiFile.cpp
Libraries/midifile/src/MidiMessage.cpp
Libraries/midifile/src/Options.cpp
)

target_include_directories(App
PRIVATE ./Utils
PRIVATE ./Project
PRIVATE ./Interfaces

PUBLIC ./Libraries
PUBLIC ./Libraries/midifile/include
)