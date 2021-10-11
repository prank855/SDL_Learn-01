@echo off
:: This script compiles all .cpp files it can find
:: (definitely not the best way of doing this)
call cmd_vars.bat
del /S/Q %tempFolder% > nul 2> nul
echo Deleted past compiled files
for /r %%v in (*.cpp) do (
call compile_file.bat "%%v" %%~nv
)
echo Compiled all .cpp files