set PROGRAM="%~1"
%PROGRAM% 10 > 80
if %ERRORLEVEL% EQU 1 goto error 
%PROGRAM% 12 > 48
if %ERRORLEVEL% EQU 1 goto error
%PROGRAM% 0 > 255
if %ERRORLEVEL% NEQ 1 goto error
%PROGRAM% 0 > 0
if %ERRORLEVEL% EQU 1 goto error
%PROGRAM% 1 > 128
if %ERRORLEVEL% EQU 1 goto error
%PROGRAM% 255 > 0
if %ERRORLEVEL% NEQ 1 goto error
%PROGRAM% 255 > 255
if %ERRORLEVEL% EQU 1 goto error
%PROGRAM% 256 > "Enter correct number"
if %ERRORLEVEL% EQU 1 goto error
echo Successful program testing
exit 0
