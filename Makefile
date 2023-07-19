hello:
	echo "Hello, World"
	g++ main.cpp glad.c -o main -I ./include -L ./libs/darwin-arm64 -lglfw3 -lassimp -framework Cocoa -framework OpenGL -framework IOKit
	./main