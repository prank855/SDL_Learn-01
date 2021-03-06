@echo off
:: this file sets variables for other scripts to use

:: please set these variables yourself
    :: location of sdl2/sdl2_image folders
    set depLocation=C:\\deps
    :: location of mingw binaries
    set mingwBin=C:\\ProgramData\\chocolatey\\lib\\mingw\\tools\\install\\mingw64\\bin

:: dont edit anything under this line

:: temp folder location
set tempFolder=temp

set c_standard=-std=c++20

:: DEBUG FLAGS
:: allow debug, compile fast, set c++ standard, allow error checking output
set debug_pre_flags=-g -O0

:: BUILD FLAGS
:: compile for speed, set c++ standard, allow error checking output, remove external console
set build_pre_flags=-O3 -Wl,--subsystem,windows -mwindows

:: defines includes
set includes=-I%depLocation%\\SDL2-2.0.16\\x86_64-w64-mingw32\\include\\SDL2 -I%depLocation%\\SDL2_image-2.0.5\\x86_64-w64-mingw32\\include\\SDL2

:: linker locations
set linker=-L%depLocation%\\SDL2-2.0.16\\x86_64-w64-mingw32\\lib -L%depLocation%\\SDL2_image-2.0.5\\x86_64-w64-mingw32\\lib

:: sdl flags
set flags=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image