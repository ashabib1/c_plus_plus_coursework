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
#include "person.h"

using namespace std;

class Game {
public:
	Game();
	Game(Person* one, Person* two);
	vector<string> start_game();
	void print_game();
	bool isValid(string coord);
	bool isTaken(string coord);
	vector<string> add_symbol(string coord, string turn);
	bool gameOver();
	void body(Person* ThePlayerOne, Person* ThePlayerTwo, Game G);
	void gameEnd(Person* ThePlayerOne, Person* ThePlayerTwo, Game G);
private:
	vector<string> gameVec;
	int nRounds;
	Person* P1;
	Person* P2;
	bool taken[9];
};
