DIR=./build/src/mas.o ./build/src/end.o ./build/src/life.o ./build/src/Goddess_bless.o 

.PHONY:clean
all:god test

god: ./build/src/end.o ./build/src/life.o ./build/src/mas.o ./build/src/Goddess_bless.o 
	g++ -std=c++11 -Wall -Werror $(DIR) -o ./bin/god -ISFML1\include -LSFML1\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lfreetype

test: ./build/src/end.o ./build/src/life.o ./build/src/mas.o ./build/test/test.o
	g++ -std=c++17 -Wall -Werror -o ./bin/test ./build/src/end.o ./build/src/life.o ./build/src/mas.o ./build/test/test.o -lm
	./bin/test

./build/src/Goddess_bless.o: ./src/Goddess_bless.cpp	
	g++ -std=c++17 -c ./src/Goddess_bless.cpp -o ./build/src/Goddess_bless.o -ISFML1\include -lm

./build/src/end.o: ./src/end.cpp	
	g++ -std=c++17 -Wall -Werror -c ./src/end.cpp -o ./build/src/end.o -lm
	
./build/src/life.o: ./src/life.cpp	
	g++ -std=c++17 -Wall -Werror -c ./src/life.cpp -o ./build/src/life.o -lm	
	
./build/src/mas.o: ./src/mas.cpp	
	g++ -std=c++17 -Wall -Werror -c ./src/mas.cpp -o ./build/src/mas.o -lm

./build/test/test.o: ./test/test.cpp
	g++ -std=c++17 -c ./test/test.cpp  -o  ./build/test/test.o -ISFML1\include -LSFML1\lib -lm
	
	
clean:
	rm -rf ./build/src/*.o ./build/test/*.o