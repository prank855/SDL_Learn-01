@echo off
::copies dll files to bin folder
call cmd_vars.bat

:: get SDL2.dll
copy %depLocation%\\SDL2-2.0.16\\x86_64-w64-mingw32\\bin\\SDL2.dll bin\\SDL2.dll >nul
copy %depLocation%\\SDL2_image-2.0.5\x86_64-w64-mingw32\bin\\SDL2_image.dll bin\\SDL2_image.dll >nul
copy "%mingwBin%\\libstdc++-6.dll" "bin\\libstdc++-6.dll" >nul
copy %mingwBin%\\libgcc_s_seh-1.dll bin\\libgcc_s_seh-1.dll >nul
copy %mingwBin%\\libwinpthread-1.dll bin\\libwinpthread-1.dll >nul

echo Copied all required DLL's
