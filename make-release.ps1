cmake -G Ninja -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build

write-host "------------ Build Finished ------------"

./run.ps1