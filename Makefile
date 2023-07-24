run:
	echo "Running..."
	g++ -std=c++11 main.cpp ./libs/glad.c -o main -I ./ -I ./include -I ./include/freetype2 -L ./libs/darwin-arm64 -lglfw3 -lassimp -lfreetype -framework Cocoa -framework OpenGL -framework IOKit
	./main

clean:
	rm ./main

save:
	git add .
	git commit -m "auto commit"
	git push origin main