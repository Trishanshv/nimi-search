# Nimi Search (C++ / CMake)
    A note on the name:If (you are wondering why it is named nimi search || you assumed that it might have been a typo)
    {sorry to say this but i have a very bad naming sense}

## Build (MinGW / MSYS2)
1. Open MSYS2 MinGW64 shell.
2. mkdir build && cd build
3. cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
4. mingw32-make
5. ./mini_search_engine.exe

## Notes
- Uses C++17.
- No `std::vector` (custom arrays / raw arrays used later).
