:loop
makedata.exe
test.exe
sample.exe
fc test.out sample.out
if %errorlevel%==0 goto loop
pause 
