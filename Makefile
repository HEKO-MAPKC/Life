DIR=./build/src/Goddess_bless.o ./build/src/end.o
.PHONY:clean
god: ./build/src/end.o ./build/src/Goddess_bless.o 
	g++ $(DIR) -o ./bin/god -DSFML_STATIC -ID:\LABA\Note\SFML\include -LD:\LABA\Note\SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-audio-s -lopengl32 -lwinmm -lgdi32 -lfreetype 

./build/src/Goddess_bless.o: ./src/Goddess_bless.cpp	
	g++ -std=c++17 -c -o ./build/src/Goddess_bless.o -c ./src/Goddess_bless.cpp -DSFML_STATIC -ID:\LABA\Note\SFML\include -lm

./build/src/end.o: ./src/end.cpp	
	g++ -std=c++11 -c  -Wall -Werror -c ./src/end.cpp -o ./build/src/end.o -lm	
	
clean:
	rm -rf ./build/src/*.o ./build/test/*.o