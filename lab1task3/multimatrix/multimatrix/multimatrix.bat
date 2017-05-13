set PROGRAM="%~1"
%PROGRAM% matrix1.txt matrix2.txt > matrix4.txt
if %ERRORLEVEL% EQU 1 goto error 
%PROGRAM% matrix2.txt matrix1.txt > matrix5.txt
if %ERRORLEVEL% EQU 1 goto error
%PROGRAM% matrix.txt > matrix3.txt
if %ERRORLEVEL% NEQ 1 goto error
echo Successful program testing
exit 0