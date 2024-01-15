@echo off
mkdir build 
cd build
cmake .. -A Win32 
cmake --build .
if errorlevel 1 pause
cd Debug
cls
dxstl.exe
cd ..
cd ..
pause
