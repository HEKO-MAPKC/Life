#include <iostream>
using namespace std;

int num_life(int** world, int n, int x, int y)
{
    int num = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (x + i < n && y + j < n && x + i >= 0 && y + j >= 0
                && !(i == 0 && j == 0)) {
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
    } else {
        return num;
    }
}

void day(int** world, int** world_after, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (world[i][j] == 0) {
                if (num_life(world, n, i, j) == 3) {
                    world_after[i][j] = 1;
                }
            } else {
                if (num_life(world, n, i, j) != 0) {
                    world_after[i][j] = 1;
                }
            }
        }
    }
}
