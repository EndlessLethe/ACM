:loop
makedata.exe
try.exe
test.exe
fc a.out b.out
if %errorlevel%==0 goto loop
pause 