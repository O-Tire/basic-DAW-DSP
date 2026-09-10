cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build

write-host "------------ Build Finished ------------"

./build/Debug/App.exe