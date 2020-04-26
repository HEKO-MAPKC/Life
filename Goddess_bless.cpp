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
void out_mas(int** mas, int n) { //вывод массива
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

void day(int** world, int** world_after, int n) { //один день эволюции
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

void Init_Graphics() {
	RenderWindow window(VideoMode(1000, 1000), "Богиня благославляет этот ПК");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.display();
	}
}

int main()
{
	//инициализация
	int n = 5, day_num = 1, coord_num = 10; //размер мира
	string* coord_world;
	coord_world = new string[coord_num];
	int** world;  //мир
	world = new int* [n];
	int** world_after; //мир после дня эволюции
	world_after = new int* [n];
	int** world_before;  //мир
	world_before = new int* [n];
	for (int i = 0; i < coord_num; i++) {
		coord_world[i] = to_string(i);
	}
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
	Init_Graphics();
	get_coordinates(world_after, coord_world[day_num % (coord_num)], n);
	//out_mas(world, n);
	while (1) {
		day(world, world_after, n);
		day_num++;
		_getch();
		//out_mas(world_after, n);
		get_coordinates(world_after, coord_world[day_num % (coord_num)], n);
		if (compare_coordinates(coord_world, coord_num)) {
			//cout << "Compare_coord" << endl;
			break;
		}
		copy_mas(world, world_after, n);
		null_mas(world_after, n);
		if (check_null_world(world, n)) {
			//cout << "Check" << endl;
			break;
		}
	}
    return 0;
}