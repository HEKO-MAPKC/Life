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