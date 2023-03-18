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

using namespace std;

class Node {
public:
	Node(int s);
private:
	int data;
	Node* previous;
	Node* next;
	friend class List;
	friend class Iterator;
};