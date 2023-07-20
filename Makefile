run:
	echo "Running..."
	rm ./main
	g++ main.cpp ./libs/glad.c -o main -I ./include -L ./libs/darwin-arm64 -lglfw3 -lassimp -framework Cocoa -framework OpenGL -framework IOKit
	./main

save:
	git add .
	git commit -m "auto commit"
	git push origin master