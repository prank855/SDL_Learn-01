@echo off
:: this file sets variables for other scripts to use

:: please set variable yourself, needs SDL2-2.0.16 & SDL2_image-2.0.5 folders
set depLocation=C:\\deps
set mingwBin=C:\\ProgramData\\chocolatey\\lib\\mingw\\tools\\install\\mingw64\\bin

:: temp folder location
set tempFolder=temp

:: DEBUG FLAGS
:: allow debug, compile fast, set c++ standard, allow error checking output
set debug_pre_flags=-g -O0 --std=c++20 -Wall

:: BUILD FLAGS
:: compile for speed, set c++ standard, allow error checking output
set build_pre_flags=-O2 --std=c++20 -Wl,--subsystem,windows -mwindows

:: defines includes
set includes=-I%depLocation%\\SDL2-2.0.16\\x86_64-w64-mingw32\\include\\SDL2 -I%depLocation%\\SDL2_image-2.0.5\\x86_64-w64-mingw32\\include\\SDL2

:: linker locations
set linker=-L%depLocation%\\SDL2-2.0.16\\x86_64-w64-mingw32\\lib -L%depLocation%\\SDL2_image-2.0.5\\x86_64-w64-mingw32\\lib

:: sdl flags
set flags=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image