/*
PIC 10B 2A, Homework 3
Purpose: File Comparer
Author: Adnan Shabib
Date: 11/07/2021
*/
#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <vector>

using namespace std;

class textfile {
public:
	textfile(ifstream& s);
	bool operator>(textfile s);
	bool operator==(textfile s);
private:
	ifstream& thefile;
};