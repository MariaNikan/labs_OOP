set PROGRAM="%~1"
%PROGRAM% 6 > number2.txt
if %ERRORLEVEL% EQU 1 goto error 
%PROGRAM% 0 > number1.txt
if %ERRORLEVEL% EQU 1 goto error
%PROGRAM% 256 > number3.txt
if %ERRORLEVEL% EQU 1 goto error
%PROGRAM%  > number4.txt
if %ERRORLEVEL% EQU 1 goto error
echo Successful program testing
exit 0
