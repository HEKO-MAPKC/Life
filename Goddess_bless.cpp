#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;

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
				cout << 0 << endl;
				return 0;
			}
		}
	}

	if (num < 2) {
		cout << 0 << endl;
		return 0;
	}
	else {
		cout << num << endl;
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

int proverka1(int** mas1, int n) {
	int v=0;
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


int main() {
	//инициализация
	int n = 5; //размер мира
	int** world;  //мир
	world = new int* [n];
	int** world_after; //мир после дня эволюции
	world_after = new int* [n];
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
	world[0][1] = 1;
	world[1][0] = 1;
	world[1][1] = 1;
	world[2][2] = 1;
	world[3][3] = 1;
	world[4][4] = 1;
	world[4][1] = 1;
	world[1][4] = 1;
	out_mas(world, n);
	while (1) {
		day(world, world_after, n);
		_getch();
		out_mas(world_after, n);
		copy_mas(world, world_after, n);
		null_mas(world_after, n);
		if (proverka1(world, n)) break;
	}
	return 0;
}

