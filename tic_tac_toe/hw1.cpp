/*
PIC 10B 2B, Homework 1
Purpose: Tic-tac-toe game
Author: Adnan Shabib
Date: 10/18/2021
*/

#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "person.h"
#include "game.h"

using namespace std;

int main() {

	int nGames;
	string playerOne;
	string playerTwo;
	cout << "How many games would you like to play? ";
	cin >> nGames;
	cout << "Who is Player One? ";
	cin >> playerOne;
	cout << "Who is Player Two? ";
	cin >> playerTwo;
	cout << endl;
	Person* ThePlayerOne = new Person(playerOne);
	Person* ThePlayerTwo = new Person(playerTwo);
	Game G(ThePlayerOne, ThePlayerTwo);

	while (nGames > 0) {
		G.body(ThePlayerOne, ThePlayerTwo, G);
		nGames--;
	}

	G.gameEnd(ThePlayerOne, ThePlayerTwo, G);

	return 0;
}

