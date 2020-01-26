@echo off

set BuildDir=build\

IF NOT EXIST %BuildDir% mkdir %BuildDir%

pushd %BuildDir%

cl -Zi /O2 ..\src\UnityBuild.cpp user32.lib opengl32.lib gdi32.lib ws2_32.lib

popd