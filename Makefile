.PHONY:clean
CXX=g++
OBJ=./build/src/mas.o ./build/src/end.o ./build/src/life.o ./build/src/Goddess_bless.o 
OBJJ=./build/src/end.o ./build/src/life.o ./build/src/mas.o ./build/test/test.o
LIB= -ISFML1\include -LSFML1\lib
LDFLAGS=-Wall -Werror
STD=-std=c++17
SFM=-lsfml-graphics -lsfml-window -lsfml-system

all:god test

god: $(OBJ)
	$(CXX) $(STD) $(LDFLAGS) $(OBJ) -o ./bin/god $(LIB) $(SFM)

test: $(OBJJ)
	$(CXX) -std=c++17 $(LDFLAGS) -o ./bin/test $(OBJJ) -lm
	./bin/test

./build/src/Goddess_bless.o: ./src/Goddess_bless.cpp	
	$(CXX) $(STD) -c ./src/Goddess_bless.cpp -o ./build/src/Goddess_bless.o $(LIB) -lm

./build/src/end.o: ./src/end.cpp	
	$(CXX) $(STD) $(LDFLAGS) -c ./src/end.cpp -o ./build/src/end.o -lm
	
./build/src/life.o: ./src/life.cpp	
	$(CXX) $(STD) $(LDFLAGS) -c ./src/life.cpp -o ./build/src/life.o -lm	
	
./build/src/mas.o: ./src/mas.cpp	
	$(CXX) $(STD) $(LDFLAGS) -c ./src/mas.cpp -o ./build/src/mas.o -lm

./build/test/test.o: ./test/test.cpp
	$(CXX) $(STD) -c ./test/test.cpp  -o  ./build/test/test.o -lm

clean:
	rm -rf ./build/src/*.o ./build/test/*.o