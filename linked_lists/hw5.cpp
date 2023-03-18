/*
PIC 10B 2A, Homework 5
Purpose: Lists
Author: Michelle Tepoyan
Date: 11/30/2021
*/

#include <iostream>
#include <string>
#include <vector>
#include "Iterator.h"
#include "List.h"
#include "Node.h"

using namespace std;

int main() {
	Iterator pos;
	List numbers;
	int tempIn;
	int index;
	int val;
	cout << "Please input a set of nonnegative numbers for a List" << endl;
	cout << "(Enter -1 when you are finished):" << endl << endl;
	for (int i = 0; i < 1000; i++) {
		cin >> tempIn;
		if (tempIn == -1)
			break;
		else
			numbers.push_back(tempIn);
	}
	cout << "Your list is" << endl;
	cout << "(";
	for (pos = numbers.begin(); pos != numbers.end(); pos++)
		cout << *pos << ",";
	cout << '\b';
	cout << ")" << endl << endl;
	cout << "Select an index for insertion (enter -1 when finished): ";
	cin >> index;
	while (index != -1) {
		cout << "Select a value for insertion: ";
		cin >> val;
		pos = numbers.begin();
		for (int j = 0; j < index; j++)
			pos++;
		numbers.insert(pos, val);
		cout << "Select an index for insertion (enter -1 when finished): ";
		cin >> index;
	}
	cout << endl << endl;
	cout << "The augmented List is" << endl;
	cout << "(";
	for (pos = numbers.begin(); pos != numbers.end(); pos++)
		cout << *pos << ",";
	cout << '\b';
	cout << ")" << endl;
	cout << endl;
	cout << "When we sort the previous list we obtain" << endl;
	numbers.sort();
	cout << "(";
	for (pos = numbers.begin(); pos != numbers.end(); pos++)
		cout << *pos << ",";
	cout << '\b';
	cout << ")" << endl;
	cout << "And this sorted list in reverse order is" << endl;
	numbers.reverse();
	cout << "(";
	for (pos = numbers.begin(); pos != numbers.end(); pos++)
		cout << *pos << ",";
	cout << '\b';
	cout << ")" << endl;
	cout << "If we merge this list with the list (2,3,5,7,11) we obtain" << endl;
	numbers.merge();
	cout << "(";
	for (pos = numbers.begin(); pos != numbers.end(); pos++)
		cout << *pos << ",";
	cout << '\b';
	cout << ")" << endl;
	return 0;
}