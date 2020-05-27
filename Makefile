DIR=./build/src/mas.o ./build/src/end.o ./build/src/life.o ./build/src/Goddess_bless.o 

.PHONY:clean
all:god

god: ./build/src/end.o ./build/src/life.o ./build/src/mas.o ./build/src/Goddess_bless.o 
	g++ $(DIR) -o ./bin/god -DSFML_STATIC -ID:\LABA\Note\SFML\include -LD:\LABA\Note\SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-audio-s -lopengl32 -lwinmm -lgdi32 -lfreetype 

./build/src/Goddess_bless.o: ./src/Goddess_bless.cpp	
	g++ -c ./src/Goddess_bless.cpp -o ./build/src/Goddess_bless.o  -DSFML_STATIC -ID:\LABA\Note\SFML\include -lm

./build/src/end.o: ./src/end.cpp	
	g++ -Wall -Werror -c ./src/end.cpp -o ./build/src/end.o -lm
	
./build/src/life.o: ./src/life.cpp	
	g++ -Wall -Werror -c ./src/life.cpp -o ./build/src/life.o -lm	
	
./build/src/mas.o: ./src/mas.cpp	
	g++ -Wall -Werror -c ./src/mas.cpp -o ./build/src/mas.o -lm
	
	
clean:
	rm -rf ./build/src/*.o ./build/test/*.o