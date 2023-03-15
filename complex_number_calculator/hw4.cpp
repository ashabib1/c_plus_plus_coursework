#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include "ComplexVector.h"

using namespace std;

int main() {
	ComplexVector x("{ 2 + 4 i, 3 + 5 i, -1 - 3 i, 8 + 10 i}");
	ComplexVector y("{ -10 + 3.5 i, 4 + 7.3 i, 2 - 8 i, 10 - 142 i}");
	x.putinarray();
	x.getNumbers();
	y.putinarray();
	y.getNumbers();
	cout << "v1 = { 2 + 4 i, 3 + 5 i, -1 - 3 i, 8 + 10 i}" << endl;
	cout << "v2 = { -10 + 3.5 i, 4 + 7.3 i, 2 - 8 i, 10 - 142 i}" << endl;
	cout << "v1 + v2 = " << x + y << endl;
	cout << "v1 - v2 = " << x - y << endl;
	cout << "v1 * v2 = " << x * y << endl;
	cout << "v1 / v2 = " << x / y << endl;

	ComplexVector z2("{ 1 + 1 i}");
	z2.recursiveOutput(5, z2);
	z2.printRecursive();
	
}