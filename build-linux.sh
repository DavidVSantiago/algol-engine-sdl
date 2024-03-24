mkdir -p bin/linux
/usr/bin/g++ -fdiagnostics-color=always -g src/main.cpp src/engine/Engine.h src/engine/Engine.cpp -o bin/linux/main -IC:/usr/include/SDL2 -LC:/usr/lib/x86_64-linux-gnu -lSDL2main -lSDL2
