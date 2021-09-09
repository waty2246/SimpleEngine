@echo off
pushd ..
xcopy /ys configs modules
devtools\premake5.exe %* --location_path=_ 
xcopy /ys assets _
popd
pause