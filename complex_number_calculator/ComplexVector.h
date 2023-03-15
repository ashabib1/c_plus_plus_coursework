#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <vector>

using namespace std;

class ComplexVector {
public:
	ComplexVector(string x);
	friend string operator+(ComplexVector s, ComplexVector t);
	friend string operator-(ComplexVector s, ComplexVector t);
	friend string operator*(ComplexVector s, ComplexVector t);
	friend string operator/(ComplexVector s, ComplexVector t);
	friend string operator%(ComplexVector s, int z);
	friend string operator<(ComplexVector s, int z);
	friend string operator>(ComplexVector s, ComplexVector t);
	friend string operator<=(ComplexVector s, ComplexVector t);
	int getLength();
	vector<string> getNumbers();
	vector<string> putinarray();
	vector<string> getArray();
	void recursiveOutput(int x, ComplexVector n);
	void printRecursive();
private:
	string recPrint;
	bool tr = true;
	int rx = 0;
	int tx = 0;
	string fig[50];
	vector<string> numbers;
	vector<string> strnumbers;
	string z;
};