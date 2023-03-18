/*
PIC 10B 2A, Homework 5
Purpose: Lists
Author: Michelle Tepoyan
Date: 11/30/2021
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <list>
#include <cassert>
#include "Iterator.h"

Iterator::Iterator() {
	position = NULL;
	container = NULL;
}

int Iterator::operator*() const {
	assert(position != nullptr);
	return position->data;
}

Iterator& Iterator::operator++(int x) {
	assert(position != nullptr);
	position = position->next;
	return *this;
}

Iterator& Iterator::operator--(int x) {
	assert(position != container->first);
	if (position == nullptr)
		position = container->last;
	else
		position = position->previous;
	return *this;
}

bool Iterator::operator==(const Iterator& b) const {
	return position == b.position;
}

bool Iterator::operator!=(const Iterator& b) const {
	return position != b.position;
}