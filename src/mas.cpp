#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

void rand_mas(int** mas, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mas[i][j] = rand() % 2;
        }
    }
}
int compare_mas(int** mas1, int** mas2, int n)
{
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

void null_mas(int** mas, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mas[i][j] = 0;
        }
    }
}
void copy_mas(int** mas1, int** mas2, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mas1[i][j] = mas2[i][j];
        }
    }
}
