#!/bin/bash
COMPILER=/usr/bin/g++
OUTPUT=bin/linux/main
SDL_INCLUDE=/usr/include/SDL2
SDL_LIB=/usr/lib/x86_64-linux-gnu

# Lê todas as linhas do arquivo compile_sources.txt
while read -r linha; do
  SOURCES="$SOURCES $linha"
done < compile_sources.txt

# Lê todas as linhas do arquivo compile_SDLparams.txt
while read -r linha; do
  PARAMS="$PARAMS $linha"
done < compile_SDLparams.txt

# execução
$COMPILER -fdiagnostics-color=always -g $SOURCES -o $OUTPUT -I$SDL_INCLUDE -D_REENTRANT -L$SDL_LIB $PARAMS -Wl,-rpath,$SDL_LIB -Wl,--enable-new-dtags -Wl,-Bstatic -Wl,-Bdynamic -lm -ldl -lpthread -lrt
