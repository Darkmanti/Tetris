@echo off

set BuildDirSrc=build\
set BuildDirMetaEnum=meta\MetaEnumGen\build\

IF NOT EXIST %BuildDirSrc% mkdir %BuildDirSrc%
IF NOT EXIST %BuildDirMetaEnum% mkdir %BuildDirMetaEnum%

pushd %BuildDirMetaEnum%
cl /O2 ..\MetaEnum\main.cpp user32.lib gdi32.lib
main.exe
popd

pushd %BuildDirSrc%
cl -Zi /O2 ..\src\UnityBuild.cpp user32.lib opengl32.lib gdi32.lib ws2_32.lib
popd