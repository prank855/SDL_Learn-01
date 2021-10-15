@echo off
call cmd_vars.bat
g++ src/*.cpp src/plx/*.cpp src/plx/systems/*.cpp src/plx/components/*.cpp %build_pre_flags% %includes% %linker% %flags% -o bin/forced.exe