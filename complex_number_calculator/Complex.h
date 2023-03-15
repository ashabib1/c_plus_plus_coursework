#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include "ComplexVector.h"

using namespace std;

class Complex {
	friend class ComplexVector;
public:
	Complex();
	void recursiveOutput(int x);
};