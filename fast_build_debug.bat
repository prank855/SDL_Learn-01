@echo off
:: Builds the debuggable executable, needs all cpp files to be precompiled using compile_ALL_files.bat
call cmd_vars.bat

if not exist fdebug (
    echo First Time Fast Debug Setup
    call compile_ALL_files.bat
    echo . > fdebug
)

if exist hcheck (
    echo Header file changed, recompiling all files...
    call compile_ALL_files.bat
    del hcheck
) else (
    echo Fast Debug Started...
)

call clean.bat
call copy_dll.bat
:: build compiled files to executable
echo g++ temp/*.o -o bin/debug.exe %debug_pre_flags% %linker% %flags%
g++ temp/*.o -o bin/debug.exe %debug_pre_flags% %linker% %flags%
echo Built debug.exe