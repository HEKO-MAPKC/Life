#define CATCH_CONFIG_MAIN
#include "../athirdparty/catch.hpp"
#include "../src/end.hpp"
#include "../src/life.hpp"
#include "../src/mas.hpp"
#include <iostream>
#include <string.h>
using namespace std;
TEST_CASE("Check_null_world are computed", "[check_null_world]")
{
    const int n = 4;
    int** a;
    a = new int*[n];
    int** b;
    b = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        b[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
            b[i][j] = 1;
        }
    }
    const int resulta = check_null_world(a, n);
    const int expecteda = 1;
    const int resultb = check_null_world(b, n);
    const int expectedb = 0;
    REQUIRE(expecteda == resulta);
    REQUIRE(expectedb == resultb);
}

TEST_CASE("Null_compare_coord are computed", "[null_compare_coord]")
{
    string* a;
    const int n = 5;
    a = new string[n];
    null_compare_coord(a, n);
    REQUIRE(a[0] == "0");
    REQUIRE(a[1] == "1");
    REQUIRE(a[2] == "2");
    REQUIRE(a[3] == "3");
    REQUIRE(a[4] == "4");
}

TEST_CASE("Compare_coordinates are computed", "[compare_coordinates]")
{
    string* a;
    string* b;
    const int n = 2;
    a = new string[n];
    b = new string[n];
    a[0] = "1234";
    a[1] = "1234";
    b[0] = "1234";
    b[1] = "1231";
    const int expecteda = 1;
    const int expectedb = 0;
    REQUIRE(compare_coordinates(a, n) == expecteda);
    REQUIRE(compare_coordinates(b, n) == expectedb);
}

TEST_CASE("Get_coordinates are computed", "[get_coordinates]")
{
    const int k = 2;
    int** a;
    a = new int*[k];
    for (int i = 0; i < k; i++) {
        a[i] = new int[k];
    }
    const int n = 1;
    string* b;
    b = new string[n];
    a[0][0] = 0;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 0;
    get_coordinates(a, b[0], k);
    REQUIRE(b[0] == "0110");
}

TEST_CASE("Day are computed", "[day]")
{
    const int n = 2;
    int** a;
    a = new int*[n];
    int** b;
    b = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        b[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = 0;
        }
    }
    a[0][0] = 1;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 0;
    day(a, b, n);
    REQUIRE(b[0][0] == 1);
    REQUIRE(b[0][1] == 1);
    REQUIRE(b[1][0] == 1);
    REQUIRE(b[1][1] == 1);
}

TEST_CASE("Num_life are computed", "[num_life]")
{
    const int n = 2;
    int** a;
    a = new int*[n];
    int** b;
    b = new int*[n];
    int** c;
    c = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        b[i] = new int[n];
        c[i] = new int[n];
    }
    a[0][0] = 1;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 0;
    b[0][0] = 1;
    b[0][1] = 0;
    b[1][0] = 0;
    b[1][1] = 0;
    c[0][0] = 1;
    c[0][1] = 1;
    c[1][0] = 0;
    c[1][1] = 0;
    REQUIRE(num_life(a, n, 1, 1) == 3);
    REQUIRE(num_life(c, n, 1, 0) == 2);
    REQUIRE(num_life(b, n, 0, 0) == 0);
}

TEST_CASE("Copy_mas are computed", "[copy_mas]")
{
    const int n = 1;
    int** a;
    a = new int*[n];
    int** b;
    b = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        b[i] = new int[n];
    }
    a[0][0] = 0;
    b[0][0] = 1;
    copy_mas(a, b, n);
    REQUIRE(a[0][0] == b[0][0]);
}

TEST_CASE("Null_mas are computed", "[null_mas]")
{
    const int n = 1;
    int** a;
    a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }
    a[0][0] = 1;
    null_mas(a, n);
    REQUIRE(a[0][0] == 0);
}
