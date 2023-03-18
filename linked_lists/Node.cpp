/*
PIC 10B 2A, Homework 5
Purpose: Lists
Author: Michelle Tepoyan
Date: 11/30/2021
*/

#include "Node.h"

Node::Node(int s) {
	data = s;
	previous = NULL;
	next = NULL;
}