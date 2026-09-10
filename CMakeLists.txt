cmake_minimum_required(VERSION 3.1)

project(App)

add_executable(App 
Main.cpp
Utils/Synth.cpp
Utils/AudioEngine.cpp
Utils/ClipManager.cpp
Utils/DAW.cpp
Utils/Project.cpp
)

target_include_directories(App PUBLIC
./Libraries
)