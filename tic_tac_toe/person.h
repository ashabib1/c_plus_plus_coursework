/*
PIC 10B 2B, Homework 1
Purpose: Tic-tac-toe game
Author: Adnan Shabib
Date: 10/18/2021
*/

#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person {
public:
	Person();
	Person(string playerName);
	string getName();
	int getScore();
	void addScore();
private:
	string name;
	int score;
};