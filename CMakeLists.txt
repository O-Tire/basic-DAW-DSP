cmake_minimum_required(VERSION 3.0)

project(App)

add_executable(App 
Main.cpp
Utils/Synth.cpp
Utils/AudioEngine.cpp
)

# FOR THE MINIAUDIO LIBRARY #

target_include_directories(App PUBLIC
./libraries
)