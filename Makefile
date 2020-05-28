DIR=./build/src/mas.o ./build/src/end.o ./build/src/life.o ./build/src/Goddess_bless.o 

.PHONY:clean
all:god

god: ./build/src/end.o ./build/src/life.o ./build/src/mas.o ./build/src/Goddess_bless.o 
	g++ -std=c++11 -Wall -Werror $(DIR) -o ./bin/god -ISFML1\include -LSFML1\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lopengl32 -lwinmm -lgdi32 -lfreetype 

./build/src/Goddess_bless.o: ./src/Goddess_bless.cpp	
	g++ -std=c++17 -c ./src/Goddess_bless.cpp -o ./build/src/Goddess_bless.o -ISFML1\include -lm

./build/src/end.o: ./src/end.cpp	
	g++ -std=c++17 -Wall -Werror -c ./src/end.cpp -o ./build/src/end.o -lm
	
./build/src/life.o: ./src/life.cpp	
	g++ -std=c++17 -Wall -Werror -c ./src/life.cpp -o ./build/src/life.o -lm	
	
./build/src/mas.o: ./src/mas.cpp	
	g++ -std=c++17 -Wall -Werror -c ./src/mas.cpp -o ./build/src/mas.o -lm
	
	
clean:
	rm -rf ./build/src/*.o ./build/test/*.o