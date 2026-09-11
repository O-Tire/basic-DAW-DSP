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
Project/Project.cpp
)

target_include_directories(App
PUBLIC ./Libraries
PRIVATE ./Utils
PRIVATE ./Project
)