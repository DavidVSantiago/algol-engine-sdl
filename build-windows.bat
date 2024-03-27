@echo off
COMPILER=g++
OUTPUT=bin/windows/main
SDL_INCLUDE=-IC:/usr/include/SDL2
SDL_LIB=-LC:/usr/lib/x86_64-linux-gnu

rem Lê todas as linhas do arquivo compile_sources.txt
FOR /F "delims=" %%i IN ('type compile_sources.txt') DO (
    rem Concatena a linha à variável
    SET SOURCES=%SOURCES% %%i
)
rem Lê todas as linhas do arquivo compile_SDLparams.txt
FOR /F "delims=" %%i IN ('type compile_SDLparams.txt') DO (
    rem Concatena a linha à variável
    SET PARAMS=%PARAMS% %%i
)

$COMPILER -fdiagnostics-color=always -g %SOURCES% -o $OUTPUT $SDL_INCLUDE $SDL_LIB %PARAMS% -lmingw32 -mwindows
