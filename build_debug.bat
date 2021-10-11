@echo off
:: Builds the debuggable executable
call cmd_vars.bat
call clean.bat
call copy_dll.bat
:: build compiled files to executable
g++ temp/*.o -o bin/debug.exe %pre_flags% %linker% %flags%
echo Built debug.exe