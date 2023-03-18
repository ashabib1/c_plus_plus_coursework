/*
PIC 10B 2A, Homework 5
Purpose: Lists
Author: Michelle Tepoyan
Date: 11/30/2021
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Node.h"
#include "List.h"

class Iterator {
public:
	Iterator();
	int operator*() const;
	Iterator& operator++(int x);
	Iterator& operator--(int x);
	bool operator==(const Iterator& b) const;
	bool operator!=(const Iterator& b) const;
private:
	Node* position;
	const List* container;
	friend class List;
};