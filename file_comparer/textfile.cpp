/*
PIC 10B 2A, Homework 3
Purpose: File Comparer
Author: Adnan Shabib
Date: 11/07/2021
*/
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include "textfile.h"

textfile::textfile(ifstream& s) : thefile(s) {}

bool textfile::operator>(textfile s) {
	textfile td = *this;
	vector<char> firstone, secondone;
	char firstchar = (char)"";
	char secondchar = (char)"";
	int firstlinecounter = 1;
	int secondlinecounter = 1;
	for (int i = 0; i < 99999; i++) {
		td.thefile.get(firstchar);
		s.thefile.get(secondchar);
		if (firstchar != (char)"")
			firstone.push_back(firstchar);
		if (firstchar == (char)'\n')
			firstlinecounter++;
		if (secondchar != (char)"")
			secondone.push_back(secondchar);
		if (secondchar == (char)'\n')
			secondlinecounter++;
		firstchar = (char)"";
		secondchar = (char)"";
	}
	if (firstlinecounter > secondlinecounter)
		return true;
	else
		return false;
}

bool textfile::operator==(textfile s) {
	textfile td = *this;
	vector<char> firstone, secondone;
	char firstchar = (char)"";
	char secondchar = (char)"";
	int firstlinecounter = 1;
	int secondlinecounter = 1;
	for (int i = 0; i < 99999; i++) {
		td.thefile.get(firstchar);
		s.thefile.get(secondchar);
		if (firstchar != (char)"")
			firstone.push_back(firstchar);
		if (firstchar == (char)'\n')
			firstlinecounter++;
		if (secondchar != (char)"")
			secondone.push_back(secondchar);
		if (secondchar == (char)'\n')
			secondlinecounter++;
		firstchar = (char)"";
		secondchar = (char)"";
	}
	if (firstlinecounter == secondlinecounter)
		return true;
	else
		return false;
}