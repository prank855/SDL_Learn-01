@echo off
:: Compiles a single .cpp file and saves into the temp directory
call cmd_vars.bat
:: makes temp folder where compiled files will go
mkdir %tempFolder% > nul 2> nul
:: sets arguments to variables
set arg1=%1
set arg2=%2
:: replace "\" with "\\" so g++ doesnt throw a fit
set modified=%arg1:\=\\%
:: compiles the file
g++ %modified% -c %includes%
:: moves the compiled file to the temp folder
move %arg2%.o %tempFolder%\%arg2%.o >nul
echo Compiled %arg2%
