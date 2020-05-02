#include <SFML/Graphics.hpp>
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
void out_mas(int** mas, int n) { //����� �������
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

void day(int** world, int** world_after, int n) { //���� ���� ��������
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

void init_sprites() {
	
}

void init_game() {
	bool world_started=0;
	int n = 40, day_num = 1, coord_num = 10; //������ ����
	int delay_t=100;
	string* coord_world;
	coord_world = new string[coord_num];
	int** world;  //���
	world = new int* [n];
	int** world_after; //��� ����� ��� ��������
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
	world[1][1] = 1;
	world[1][2] = 1;
	world[2][1] = 1;
	world[2][2] = 1;
	world[3][2] = 1;
	world[3][3] = 1;
	world[4][4] = 1;
	world[4][1] = 1;
	world[1][4] = 1;
	init_sprites();
	get_coordinates(world_after, coord_world[day_num % (coord_num)], n);
	int startX=700, startY=50, tilesize=20;
	int pos_j, pos_i;
	Texture Goddess_t;
	Goddess_t.loadFromFile("nep.png");
	Texture fon_t;
	fon_t.loadFromFile("fon.png");
	Sprite fon;
	fon.setTexture(fon_t);
	fon.setPosition(0, 0);
	Sprite Goddess;
	Goddess.setTexture(Goddess_t);
	Goddess.setPosition(0, 100);
	RenderWindow window(VideoMode(1600, 900), "Goddess bless this PC");
	window.clear(Color::White);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed) {
				Vector2i pixelPos = Mouse::getPosition(window);//�������� ����� �������
				pos_j = (pixelPos.x - startX) / tilesize;
				pos_i = (pixelPos.y - startY) / tilesize;
				world[pos_i][pos_j]=1;
				cout << "Choosing" << endl;
			}
			if (event.type == Event::KeyPressed) {
				if (!world_started) world_started = 1;
				cout << "Key pressed" << endl;
				//else world_started = 0;
			}

		}
		window.draw(fon);
		window.draw(Goddess);
		RectangleShape rectangle(Vector2f(tilesize, tilesize));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (world[i][j] == 0) {
					rectangle.setFillColor(Color::Black);
				}
				if (world[i][j] == 1) {
					rectangle.setFillColor(Color::Green);
				}
				rectangle.setPosition(j * tilesize + startX, i * tilesize + startY);
				window.draw(rectangle);
			}
		}
		window.display();
		if (world_started) {
			day(world, world_after, n);
			day_num++;
			get_coordinates(world_after, coord_world[day_num % (coord_num)], n);
			if (compare_coordinates(coord_world, coord_num)) {
				cout << "Compare_coord" << endl;
				world_started = 0;
				null_compare_coord(coord_world, coord_num);
				get_coordinates(world_after, coord_world[day_num % (coord_num)], n);
			}
			copy_mas(world, world_after, n);
			null_mas(world_after, n);
			if (check_null_world(world, n)) {
			    cout << "Null" << endl;
				world_started = 0;
			}
			Sleep(delay_t);
		}
	}
}

int main()
{
	//�������������
	init_game();
    return 0;
}