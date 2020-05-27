
all:
	g++ -std=c++17 Goddess_bless.cpp -o Goddess_bless.exe -DSFML_STATIC -ID:\LABA\Note\SFML\include -LD:\LABA\Note\SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-audio-s -lopengl32 -lwinmm -lgdi32 -lfreetype -lm
	
god: ./build/src/Goddess_bless.o
	g++ ./build/src/Goddess_bless.o -o ./bin/god -ID:\LABA\Note\SFML\include  -LD:\LABA\Note\SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-audio-s -lopengl32 -lwinmm -lgdi32 -lfreetype -lm
	
./build/src/Goddess_bless.o: ./src/Goddess_bless.cpp	
	g++ -Werror -c -o ./build/src/Goddess_bless.o ./src/Goddess_bless.cpp -DSFML_STATIC -ID:\LABA\Note\SFML\include -lm

clean:
	rm -rf ./build/src/*.o ./build/test/*.o