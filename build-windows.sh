mkdir -p bin/windows
/usr/bin/g++ -fdiagnostics-color=always -g src/main.cpp -o bin/windows/main -IC:/usr/include/SDL2 -LC:/usr/lib/x86_64-linux-gnu -lSDL2main -lSDL2
