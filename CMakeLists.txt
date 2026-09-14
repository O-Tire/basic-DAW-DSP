cmake_minimum_required(VERSION 3.3)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(App)

add_executable(App 
Codebase/Main.cpp
Codebase/Utils/AudioEngine.cpp
Codebase/Utils/AssetLoader.cpp
Codebase/Utils/DAW.cpp
Codebase/Utils/Sequencer.cpp
Codebase/Utils/Instrument.cpp
Codebase/Utils/ADSR.cpp
Codebase/Other/Constants.cpp
Project/Project.cpp
Project/Synth.cpp

Libraries/midifile/src/Binasc.cpp
Libraries/midifile/src/MidiEvent.cpp
Libraries/midifile/src/MidiEventList.cpp
Libraries/midifile/src/MidiFile.cpp
Libraries/midifile/src/MidiMessage.cpp
Libraries/midifile/src/Options.cpp
)

target_include_directories(App
PRIVATE ./Codebase/Utils
PRIVATE ./Codebase/Interfaces
PRIVATE ./Codebase/Other
PRIVATE ./Project

PUBLIC ./Libraries
PUBLIC ./Libraries/midifile/include
)