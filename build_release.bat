@echo off
:: Builds the release executable
call cmd_vars.bat
call compile_ALL_files.bat
call clean.bat
call copy_dll.bat
:: build compiled files to executable
g++ temp/*.o -o bin/release.exe %build_pre_flags% %linker% %flags%
:: strip executable
strip bin/release.exe
echo Built ^& stripped release.exe
echo Finished.
