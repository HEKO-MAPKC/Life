#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;
using namespace sf;

void rand_mas(int** mas, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mas[i][j] = rand() % 2;
		}
	}
}
int compare_mas(int** mas1, int** mas2, int n) {
	int v = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mas1[i][j] == mas2[i][j]) {
				v++;
			}
		}
	}
	if (v == pow(n, 2)) {
		return 1;
	}
	return 0;
}
int compare_coordinates(string* coordinates, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (coordinates[i] == coordinates[j]) {
				return 1;
			}
		}
	}
	return 0;
}
void out_mas(int** mas, int n) { 
	cout << endl;
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
}

int num_life(int** world, int n, int x, int y) {
	int num = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (x + i < n && y + j < n && x + i >= 0 && y + j >= 0 && !(i == 0 && j == 0)) {
				if (world[x + i][y + j] == 1) {
					num++;
				}
			}
			if (num > 3) {
				return 0;
			}
		}
	}

	if (num < 2) {
		return 0;
	}
	else {
		return num;
	}
}

void day(int** world, int** world_after, int n) { 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (world[i][j] == 0) {
				if (num_life(world, n, i, j) == 3) {
					world_after[i][j] = 1;
				}
			}
			else {
				if (num_life(world, n, i, j) != 0) {
					world_after[i][j] = 1;
				}
			}

		}
	}
}

void null_mas(int** mas, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mas[i][j] = 0;
		}
	}
}

void copy_mas(int** mas1, int** mas2, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mas1[i][j] = mas2[i][j];
		}
	}
}

int check_null_world(int** mas1, int n) {
	int v = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mas1[i][j] == 0) {
				v++;
			}
		}
	}
	if (v == pow(n, 2)) {
		cout << "FINISH" << endl;
		return 1;
	}
	return 0;
}
void get_coordinates(int** mas, string& coord, int n) {
	coord = "";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mas[i][j]) {
				coord += to_string(i) + to_string(j);

			}
		}
	}
}

void null_compare_coord(string* coordinates, int n) {
	for (int i = 0; i < n; i++) {
		coordinates[i] = to_string(i);
	}
}

class sprite_class {

private:
	Texture texture_t;
	Sprite sprite_t;
	
public:
	void init_sprite(int x, int y, int width, int height, int pos_x, int pos_y, int num_anim, string name) {
		texture_t.loadFromFile(name);
		sprite_t.setTexture(texture_t);
		sprite_t.setTextureRect(IntRect(x * num_anim, y, width, height));
		sprite_t.setPosition(pos_x, pos_y);
	}
	void set_anim_frame(int x, int y, int width, int height, int num_anim) {
		sprite_t.setTextureRect(IntRect(x * num_anim, y, width, height));
	}
	void init_sprite(int pos_x, int pos_y, string name) {
		texture_t.loadFromFile(name);
		sprite_t.setTexture(texture_t);
		sprite_t.setPosition(pos_x, pos_y);
	}
	void sprite_draw(RenderWindow &window) {
		window.draw(sprite_t);
	}
};

class text_class {

private:
	Text text_t;
public:
	void init_text(const wstring& str, int font_size, Font &font, int pos_x, int pos_y) {
		text_t.setFont(font);
		text_t.setCharacterSize(font_size);
		text_t.setString(str);
		text_t.setPosition(pos_x, pos_y);
	}
	void set_text(const wstring& str, RenderWindow& window) {
		text_t.setString(str);
		//text_t.setPosition(pos_x, pos_y);
		window.draw(text_t);
	}
	void text_draw(RenderWindow& window) {
		window.draw(text_t);
	}
};

void init_game() {
	bool isMove = false;
	bool world_started = 0;
	int n = 100, day_num = 0, coord_num = 10;
	int delay_t = 0;
	int startX = 700, startY = 50, tilesize = 8;
	int pos_j, pos_i;
	int num_scene = 1;
	float CurrentFrame = 0;
	string* coord_world;
	coord_world = new string[coord_num];
	int** world; 
	world = new int* [n];
	int** world_after; 
	world_after = new int* [n];
	null_compare_coord(coord_world, coord_num);
	for (int i = 0; i < n; i++) {
		world[i] = new int[n];
		world_after[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			world[i][j] = 0;
			world_after[i][j] = 0;
		}
	}
	get_coordinates(world_after, coord_world[day_num % (coord_num)], n);

	Music music;
	music.openFromFile("ost.ogg");
	music.play();
	music.setLoop(true);
	music.setVolume(10.f);

	Texture Goddess_t;
	Goddess_t.loadFromFile("nep.png");

	sprite_class fon,goddess,planet,box,day_box;
	fon.init_sprite(0,0,"fon.png");
	planet.init_sprite(startX - 182, startY - 185, "planet.png");
	box.init_sprite(10, 410, "box.png");
	day_box.init_sprite(0, 0, "day.png");
	goddess.init_sprite(522, 0, 522, 800, 0, 100, 1, "nep.png");
	Font font;
	font.loadFromFile("font.ttf");
	text_class text1, text2, text3, text4,textsp,day_num_text,num_text;
	text1.init_text(L"", 30, font, 88, 660);
	text2.init_text(L"", 30, font, 88, 660+45);
	text3.init_text(L"", 30, font, 88, 660+45*2);
	text4.init_text(L"", 30, font, 88, 660+45*3);
	textsp.init_text(L"", 30, font, 105, 560);
	day_num_text.init_text(L"", 32, font, 135, 32);
	num_text.init_text(L"", 32, font, 35, 32);
	
	
	RenderWindow window(VideoMode(1600, 900), "Goddess bless this PC");
	window.clear(Color::White);
	RectangleShape rectangle(Vector2f(tilesize, tilesize));
	RectangleShape rectangle_life(Vector2f(tilesize, tilesize));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (world[i][j] == 0) {
				rectangle.setFillColor(Color::Transparent);
				rectangle.setOutlineColor(Color::Black);
				rectangle.setOutlineThickness(1);
				rectangle.setPosition(j * tilesize + startX, i * tilesize + startY);
				window.draw(rectangle);
			}
			if (world[i][j] == 1) {
				rectangle_life.setFillColor(Color::Green);
				rectangle_life.setPosition(j * tilesize + startX, i * tilesize + startY);
				window.draw(rectangle_life);
			}
		}
	}
	while (window.isOpen()) {
		switch (num_scene) {
		case 1:
			Event event;
			while (window.pollEvent(event)) {
				if (event.type == Event::Closed)
					window.close();
				if (event.type == Event::MouseButtonPressed) {
					if (Mouse::getPosition(window).x >= startX && sf::Mouse::getPosition(window).y >= startY && sf::Mouse::getPosition(window).y <= ((n - 1) * tilesize + startY) && sf::Mouse::getPosition(window).x <= ((n - 1) * tilesize + startX))
						if (event.key.code == Mouse::Left) {
							isMove = true;
						}
				}
				if (event.type == Event::MouseButtonPressed) {
					if (Mouse::getPosition(window).x >= startX && sf::Mouse::getPosition(window).y >= startY && sf::Mouse::getPosition(window).y <= ((n - 1) * tilesize + startY) && sf::Mouse::getPosition(window).x <= ((n - 1) * tilesize + startX))
						if (event.key.code == Mouse::Right) {
							Vector2i pixelPos = Mouse::getPosition(window);
							pos_j = (pixelPos.x - startX) / tilesize;
							pos_i = (pixelPos.y - startY) / tilesize;
							world[pos_i][pos_j] = 0;
						}
				}
				if (event.type == Event::MouseButtonReleased)
					if (event.key.code == Mouse::Left)
						isMove = false;
				if (isMove)
				{
					Vector2i pixelPos = Mouse::getPosition(window);
					pos_j = (pixelPos.x - startX) / tilesize;
					pos_i = (pixelPos.y - startY) / tilesize;
					world[pos_i][pos_j] = 1;
					goddess.set_anim_frame(522, 0, 522, 800, 0);
					day_num = 0;
					cout << "Choosing" << endl;
				}
				if (event.type == Event:: KeyPressed) {
					if (event.key.code == Keyboard::S) {
						world_started = 0;
					}
					if (event.key.code == Keyboard::Enter) {
						if (!world_started) world_started = 1;
						goddess.set_anim_frame(522, 0, 522, 800, 0);
						cout << "Key pressed" << endl;
					}
					if (event.key.code == Keyboard::R) {
						null_mas(world, n);
						day_num = 0;
					}
					if (event.key.code == Keyboard::Space) {
						rand_mas(world, n);
						day_num = 0;
						cout << "Key pressed SPACE" << endl;
					}
				}
			}
			fon.sprite_draw(window);
			planet.sprite_draw(window);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					rectangle_life.setPosition(j * tilesize + startX, i * tilesize + startY);
					if (world[i][j] == 1) {
						rectangle_life.setFillColor(Color(173, 255, 47));
					}
					else {
						rectangle_life.setFillColor(Color::Transparent);
						rectangle.setPosition(j * tilesize + startX, i * tilesize + startY);
					}
					window.draw(rectangle_life);
					window.draw(rectangle);
				}
			}
			window.draw(rectangle);
			if (world_started) {
				day(world, world_after, n);
				if (day_num <= 30) {
					goddess.set_anim_frame(522, 0, 522, 800, 0);
				}
				if (day_num > 100) {
					goddess.set_anim_frame(522, 0, 522, 800, 2);
				}
				day_num++;
				get_coordinates(world_after, coord_world[day_num % (coord_num)], n);
				if (compare_coordinates(coord_world, coord_num)) {
					cout << "Compare_coord" << endl;
					goddess.set_anim_frame(522, 0, 522, 800, 3);
					day_num = 0;
					world_started = 0;
					null_compare_coord(coord_world, coord_num);
					get_coordinates(world_after, coord_world[day_num % (coord_num)], n);
				}
				copy_mas(world, world_after, n);
				null_mas(world_after, n);
				/*if (check_null_world(world, n)) {
					cout << "Null" << endl;
					world_started = 0;
				}*/
				//Sleep(delay_t);
			}
			goddess.sprite_draw(window);
			box.sprite_draw(window);
			day_box.sprite_draw(window);
			num_text.set_text(L"Дней: ", window);
			day_num_text.set_text(to_wstring(day_num), window);
			text1.set_text(L"Приветствую тебя, Анон.", window);
			text2.set_text(L"Я Богиня и благословляю", window);
			text3.set_text(L"этот компьютер.", window);
			text4.set_text(L"", window);
			textsp.set_text(L"Богиня", window);
			window.display();
		break;
		case 2:

		break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	init_game();
	return 0;
}