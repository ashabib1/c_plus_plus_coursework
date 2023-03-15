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
using namespace std;

int main() {
	vector<string> count1, count2;
	string first = "";
	string second = "";
	vector<char> charcount1, charcount2;
	char fileonechar = (char)"";
	char filetwochar = (char)"";
	int file1linecounter = 0;
	int file2linecounter = 0;
	string firstname, secondname;
	cout << "Enter the name of file 1: ";
	cin >> firstname;
	cout << "Enter the name of file 2: ";
	cin >> secondname;
	ifstream file1, file2;
	ofstream mich;
	file1.open(firstname);
	file2.open(secondname);
	mich.open("Properties.txt");
	for (int r = 0; r < 99999; r++) {
		file1 >> first;
		file2 >> second;
		if (first != "")
			count1.push_back(first);
		if (second != "")
			count2.push_back(second);
		first = "";
		second = "";
	}
	file1.close();
	file2.close();
	file1.open(firstname);
	file2.open(secondname);
	for (int s = 0; s < 99999; s++) {
		file1.get(fileonechar);
		file2.get(filetwochar);
		if (fileonechar != (char)"")
			charcount1.push_back(fileonechar);
		if (fileonechar == (char)'\n')
			file1linecounter++;
		if (filetwochar != (char)"")
			charcount2.push_back(filetwochar);
		if (filetwochar == (char)'\n')
			file2linecounter++;
		fileonechar = (char)"";
		filetwochar = (char)"";
	}
	mich << "File Name: " << firstname << '\n' << "Number of characters: " << charcount1.size() - file1linecounter << '\n' << "Number of words: " << count1.size() << '\n' << '\n' << "File Name: " << secondname << '\n' << "Number of characters: " << charcount2.size() - file2linecounter << '\n' << "Number of words: " << count2.size() << '\n' << '\n';
	ifstream file1a; 
	ifstream file2a;
	ifstream file1b; 
	ifstream file2b;
	file1a.open(firstname);
	file2a.open(secondname);
	file1b.open(firstname);
	file2b.open(secondname);
	textfile a1(file1a);
	textfile b1(file2a);
	textfile c1(file1a);
	textfile d1(file2a);
	if (a1 == b1)
		mich << "The files named '" << firstname << "' and '" << secondname << "' have the same number of lines." << endl;
	if (c1 > d1)
		mich << "The file named '" << secondname << "' has less lines than '" << firstname << "'." << endl;
	else
		mich << "The file named '" << firstname << "' has less lines than '" << secondname << "'." << endl;
	return 0;
}