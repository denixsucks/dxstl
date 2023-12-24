@echo off
mkdir build 
cd build
cmake .. -A Win32
cmake --build . 
pause