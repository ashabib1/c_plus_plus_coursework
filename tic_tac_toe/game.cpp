/*
PIC 10B 2B, Homework 1
Purpose: Tic-tac-toe game
Author: Adnan Shabib
Date: 10/18/2021
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "game.h"

using namespace std;

Game::Game() {
	nRounds = 0;
}

Game::Game(Person* one, Person* two) {
	P1 = one;
	P2 = two;
}

vector<string> Game::start_game() {
	gameVec.clear();
	for (int i = 0; i <= 9; i++) {
		taken[i] = false;
	}
	for (int i = 1; i < 4; i++) {
		for (int j = 0; j < 10; j++) {
			gameVec.push_back(" ");
		}
		gameVec.push_back(to_string(i));
	}
	gameVec.push_back("\n");
	for (int k = 1; k < 4; k++) {
		for (int j = 0; j < 3; j++) {
			if (j == 1) {
				gameVec.push_back(" ");
				gameVec.push_back(to_string(k));
			}
			for (int i = 0; i < 30; i++) {
				gameVec.push_back(" ");
				if (j != 1 && i > 10 && i % 10 == 3)
					gameVec.push_back("|");
				else if (j == 1 && i > 10 && i % 10 == 1)
					gameVec.push_back("|");
			}
			gameVec.push_back("\n");
		}
		if (k < 3) {
			for (int i = 0; i < 5; i++)
				gameVec.push_back(" ");
			for (int i = 0; i < 30; i++)
				gameVec.push_back("-");
			gameVec.push_back("\n");
		}
	}

	return gameVec;
}

void Game::print_game() {
	for (int i = 0; i < gameVec.size(); i++)
		cout << gameVec[i];
}

bool Game::isValid(string coord) {
	if (coord.length() != 3)
		return false;
	if (coord[0] > 51)
		return false;
	if (coord[2] > 51)
		return false;
	if (coord[0] < 49)
		return false;
	if (coord[0] < 49)
		return false;
	return true;
}

bool Game::isTaken(string coord) {
	int first = coord[0] - 48;
	int second = coord[2] - 48;
	if (taken[(first - 1) * 3 + second] == false) {
		taken[(first - 1) * 3 + second] = true;
		return true;
	}
	else
		return false;
}

vector<string> Game::add_symbol(string coord, string turn) {
	int first = coord[0] - 48;
	int second = coord[2] - 48;
	int space = (first - 1) * 3 + second;
	if (space == 1)
		gameVec[76] = turn;
	if (space == 2)
		gameVec[87] = turn;
	if (space == 3)
		gameVec[97] = turn;
	if (space == 4)
		gameVec[213] = turn;
	if (space == 5)
		gameVec[224] = turn;
	if (space == 6)
		gameVec[234] = turn;
	if (space == 7)
		gameVec[350] = turn;
	if (space == 8)
		gameVec[361] = turn;
	if (space == 9)
		gameVec[371] = turn;
	return gameVec;
}

bool Game::gameOver() {
	if (gameVec[76] == gameVec[87] && gameVec[87] == gameVec[97] && gameVec[76] != " ")
		return true;
	else if (gameVec[76] == gameVec[213] && gameVec[213] == gameVec[350] && gameVec[76] != " ")
		return true;
	else if (gameVec[76] == gameVec[224] && gameVec[224] == gameVec[371] && gameVec[76] != " ")
		return true;
	else if (gameVec[213] == gameVec[224] && gameVec[224] == gameVec[234] && gameVec[213] != " ")
		return true;
	else if (gameVec[350] == gameVec[361] && gameVec[361] == gameVec[371] && gameVec[350] != " ")
		return true;
	else if (gameVec[87] == gameVec[224] && gameVec[224] == gameVec[361] && gameVec[87] != " ")
		return true;
	else if (gameVec[97] == gameVec[234] && gameVec[234] == gameVec[371] && gameVec[97] != " ")
		return true;
	else if (gameVec[97] == gameVec[224] && gameVec[224] == gameVec[350] && gameVec[97] != " ")
		return true;
	else
		return false;
}

void Game::body(Person* ThePlayerOne, Person* ThePlayerTwo, Game G) {
	cout << ThePlayerOne->getName() << " Score: " << ThePlayerOne->getScore() << endl;
	cout << ThePlayerTwo->getName() << " Score: " << ThePlayerTwo->getScore() << endl;
	G.start_game();
	G.print_game();
	cout << "What is your move Player One? " << endl;
	cout << "Please write your move in the form a,b where a is the row number and b is the column number." << endl;
	string moveOne;
	cin >> moveOne;
	while (!G.isValid(moveOne)) {
		cout << "Invalid Move. What is your move? ";
		cin >> moveOne;
	}
	while (!G.isTaken(moveOne)) {
		cout << "Invalid Move. What is your move? ";
		cin >> moveOne;
	}
	G.add_symbol(moveOne, "X");
	G.print_game();
	cout << "What is your move Player Two? " << endl;
	cout << "Please write your move in the form a,b where a is the row number and b is the column number." << endl;
	string moveTwo;
	cin >> moveTwo;
	while (!G.isValid(moveTwo)) {
		cout << "Invalid Move. What is your move? ";
		cin >> moveTwo;
	}
	while (!G.isTaken(moveTwo)) {
		cout << "Invalid Move. What is your move? ";
		cin >> moveTwo;
	}
	G.add_symbol(moveTwo, "O");
	G.print_game();
	cout << "What is your move Player One? " << endl;
	cout << "Please write your move in the form a,b where a is the row number and b is the column number." << endl;
	cin >> moveOne;
	while (!G.isValid(moveOne)) {
		cout << "Invalid Move. What is your move? ";
		cin >> moveOne;
	}
	while (!G.isTaken(moveOne)) {
		cout << "Invalid Move. What is your move? ";
		cin >> moveOne;
	}
	G.add_symbol(moveOne, "X");
	G.print_game();
	cout << "What is your move Player Two? " << endl;
	cout << "Please write your move in the form a,b where a is the row number and b is the column number." << endl;
	cin >> moveTwo;
	while (!G.isValid(moveTwo)) {
		cout << "Invalid Move. What is your move? ";
		cin >> moveTwo;
	}
	while (!G.isTaken(moveTwo)) {
		cout << "Invalid Move. What is your move? ";
		cin >> moveTwo;
	}
	G.add_symbol(moveTwo, "O");
	G.print_game();
	cout << "What is your move Player One? " << endl;
	cout << "Please write your move in the form a,b where a is the row number and b is the column number." << endl;
	cin >> moveOne;
	while (!G.isValid(moveOne)) {
		cout << "Invalid Move. What is your move? ";
		cin >> moveOne;
	}
	while (!G.isTaken(moveOne)) {
		cout << "Invalid Move. What is your move? ";
		cin >> moveOne;
	}
	G.add_symbol(moveOne, "X");
	G.print_game();
	if (G.gameOver()) {
		ThePlayerOne->addScore();
		cout << "Round Over! Player One Wins!" << endl;
		return;
	}
	cout << "What is your move Player Two? " << endl;
	cout << "Please write your move in the form a,b where a is the row number and b is the column number." << endl;
	cin >> moveTwo;
	while (!G.isValid(moveTwo)) {
		cout << "Invalid Move. What is your move? ";
		cin >> moveTwo;
	}
	while (!G.isTaken(moveTwo)) {
		cout << "Invalid Move. What is your move? ";
		cin >> moveTwo;
	}
	G.add_symbol(moveTwo, "O");
	G.print_game();
	if (G.gameOver()) {
		ThePlayerTwo->addScore();
		cout << "Round Over! Player Two Wins!" << endl;
		return;
	}
	cout << "What is your move Player One? " << endl;
	cout << "Please write your move in the form a,b where a is the row number and b is the column number." << endl;
	cin >> moveOne;
	while (!G.isValid(moveOne)) {
		cout << "Invalid Move. What is your move? ";
		cin >> moveOne;
	}
	while (!G.isTaken(moveOne)) {
		cout << "Invalid Move. What is your move? ";
		cin >> moveOne;
	}
	G.add_symbol(moveOne, "X");
	G.print_game();
	if (G.gameOver()) {
		ThePlayerOne->addScore();
		cout << "Round Over! Player One Wins!" << endl;
		return;
	}
	cout << "What is your move Player Two? " << endl;
	cout << "Please write your move in the form a,b where a is the row number and b is the column number." << endl;
	cin >> moveTwo;
	while (!G.isValid(moveTwo)) {
		cout << "Invalid Move. What is your move? ";
		cin >> moveTwo;
	}
	while (!G.isTaken(moveTwo)) {
		cout << "Invalid Move. What is your move? ";
		cin >> moveTwo;
	}
	G.add_symbol(moveTwo, "O");
	G.print_game();
	if (G.gameOver()) {
		ThePlayerTwo->addScore();
		cout << "Round Over! Player Two Wins!" << endl;
		return;
	}
	cout << "What is your move Player One? " << endl;
	cout << "Please write your move in the form a,b where a is the row number and b is the column number." << endl;
	cin >> moveOne;
	while (!G.isValid(moveOne)) {
		cout << "Invalid Move. What is your move? ";
		cin >> moveOne;
	}
	while (!G.isTaken(moveOne)) {
		cout << "Invalid Move. What is your move? ";
		cin >> moveOne;
	}
	G.add_symbol(moveOne, "X");
	G.print_game();
	if (G.gameOver()) {
		ThePlayerOne->addScore();
		cout << "Round Over! Player One Wins!" << endl;
		return;
	}
	cout << "Tied Round! No Points!" << endl;
}

void Game::gameEnd(Person* ThePlayerOne, Person* ThePlayerTwo, Game G) {
	
	cout << "It is the end of the game" << endl;
	cout << ThePlayerOne->getName() << " Score: " << ThePlayerOne->getScore() << endl;
	cout << ThePlayerTwo->getName() << " Score: " << ThePlayerTwo->getScore() << endl;

	if (ThePlayerOne->getScore() > ThePlayerTwo->getScore())
		cout << ThePlayerOne->getName() << " Wins! Game Over!";
	else if (ThePlayerTwo->getScore() > ThePlayerOne->getScore())
		cout << ThePlayerTwo->getName() << " Wins! Game Over!";
	else
		cout << "Tied Game! No Winner!";
	
}