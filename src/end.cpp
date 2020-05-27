#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

void get_coordinates(int** mas, string& coord, int n)
{
    coord = "";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mas[i][j]) {
                coord += to_string(i) + to_string(j);
            }
        }
    }
}
int compare_coordinates(string* coordinates, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (coordinates[i] == coordinates[j]) {
                return 1;
            }
        }
    }
    return 0;
}

void null_compare_coord(string* coordinates, int n)
{
    for (int i = 0; i < n; i++) {
        coordinates[i] = to_string(i);
    }
}
int check_null_world(int** mas1, int n)
{
    int v = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mas1[i][j] == 0) {
                v++;
            }
        }
    }
    if (v == pow(n, 2)) {
        return 1;
    }
    return 0;
}
