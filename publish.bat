@echo off
:: Freshly compile/build & Final export of program
title Publishing Game
call build_release.bat
mkdir publish > nul 2> nul
mkdir publish\game > nul 2> nul
del /S/Q publish > nul 2> nul
del /S/Q publish\game > nul 2> nul
xcopy /e bin publish\game > nul 2> nul
cd publish
7z a -t7z publish.7z -m0=lzma2 -mx=9 -aoa game/*.* >nul
echo Published 7z file to publish/publish.7z