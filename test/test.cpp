#define CATCH_CONFIG_MAIN
#include "../src/life.hpp"
#include "../src/mas.hpp"
#include "../thirdparty/catch.hpp"
#include "../src/end.hpp"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
using namespace std;
TEST_CASE("Check_null_world are computed", "[check_null_world]")
{   
	const int n=4;
    int** a;
    a = new int*[n];
	int** b;
    b = new int*[n];
	for (int i = 0; i < n; i++) {
        a[i] = new int[n];
		b[i] = new int[n];
    }
	for(int i=0;i<n;i++){
   		for(int j=0;j<n;j++){
   			a[i][j]=0;
			b[i][j]=1;
   		}
   }
    const int resulta = check_null_world(a,n);
    const int expecteda = 1;
	const int resultb = check_null_world(b,n);
    const int expectedb = 0;
    REQUIRE(expecteda == resulta);
	REQUIRE(expectedb == resultb);
}
TEST_CASE("Null_compare_coord are computed", "[null_compare_coord]")
{   
	string* a;
	const int n=5;
    a = new string[n];
	null_compare_coord(a, n); 
    REQUIRE(a[0] == "0");
	REQUIRE(a[1] == "1");
	REQUIRE(a[2] == "2");
	REQUIRE(a[3] == "3");
	REQUIRE(a[4] == "4");
}
