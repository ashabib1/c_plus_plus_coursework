/*
PIC 10B 2B, Homework 1
Purpose: Tic-tac-toe game
Author: Adnan Shabib
Date: 10/18/2021
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "person.h"

using namespace std;

Person::Person() {
	name = "Player";
	score = 0;
}

Person::Person(string playerName) {
	name = playerName;
	score = 0;
}

string Person::getName() {
	return name;
}

int Person::getScore() {
	return score;
}

void Person::addScore() {
	score++;
}