:loop
makedata.exe
AC.exe
test.exe
fc AC.txt test.txt
if %errorlevel%==0 goto loop
pause 