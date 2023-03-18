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
#include "Iterator.h"

class List {
public:
	List();
	~List();
	void push_back(int data);
	void insert(Iterator iter, int data);
	Iterator erase(Iterator iter);
	Iterator begin();
	Iterator end();
	void reverse();
	void push_front(int data);
	void sort();
	void merge();
private:
	Node* first;
	Node* last;
	friend class Iterator;
};
