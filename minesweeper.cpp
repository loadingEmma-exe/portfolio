/*
Program: minesweeperTroubleShoot.cpp
Author: Emma Raymond
Purpose: Create a working minesweeper game
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char board[6][6];//the board the user sees
int mines[6][6];//the underlying board with all the answers

void print(string x);

int main() {
	srand(time(0));
	int action; // stores 1 for dig, 0 for flag
	int rowP; // stores x cordinate
	int colP; // stores y cordinate

	int count = 0; // stores number of bombs surrounding board"rowP""colP"
	int squares = 36; // stores number of spaces to clear

	cout << "Welcome to Minesweeper! Here is your board!" << endl << endl;

	print("boardIn"); // sets all values in board to '-'

	cout << "Intializing board complete" << endl << endl;

	print("minesIn"); // sets all values in mines to 0

	cout << "Initalizing mines complete" << endl << endl;

	print("assMines"); // assigns bombs

	cout << "Mines assigned" << endl << endl;

	print("board"); // prints board to console

	cout << "Printing board complete" << endl << endl;

	while (squares != 0) {

		action = 3;
		rowP = 9;
		colP = 9;

		cout << "You have " << squares << " left to clear" << endl;

		cout << "Would you like to dig or flag? ( 0 - flag, 1 - dig) ";
		cin >> action;

		if (action == 1) {
			cout << "In what row would you like to dig? ";
			cin >> rowP;

			cout << "In what column would you like to dig? ";
			cin >> colP;

			cout << "Your going to dig " << rowP << " " << colP << endl;
			colP--;
			rowP--;

			for (int x = 0; x < 6; x++) {
				for (int y = 0; y < 6; y++) {
					if (mines[rowP][colP] == 1) { // checks to make sure you didn't click a bomb right off the bat.
						cout << "You lost" << endl;
						return 0;
					}
					else if (mines[rowP][colP] == 0) { // checks what bombs are surrounding users selected space.
						count = 0;
						if (mines[rowP - 1][colP - 1] == 1) {// check box board[rowP - 1][colP - 1]
							count++;
						}
						else if ((mines[rowP - 1][colP - 1] == 0) && (board[rowP - 1][colP - 1] != '0')) {
							board[rowP - 1][colP - 1] = '0';
							if (squares > 0) {
								squares--;
							}
						}

						if (mines[rowP - 1][colP] == 1) {// check box board[rowP - 1][colP]
							count++;
						}
						else if ((mines[rowP - 1][colP] == 0) && (board[rowP - 1][colP] != '0')) {
							board[rowP - 1][colP] = '0';
							if (squares > 0) {
								squares--;
							}
						}

						if (mines[rowP - 1][colP + 1] == 1) {// check box board[rowP - 1][colP + 1]
							count++;
						}
						else if ((mines[rowP - 1][colP + 1] == 0) && (board[rowP - 1][colP + 1] != '0')) {
							board[rowP - 1][colP + 1] = '0';
							if (squares > 0) {
								squares--;
							}
						}

						if (mines[rowP][colP - 1] == 1) {// check box board[rowP][colP - 1]
							count++;
						}
						else if ((mines[rowP][colP - 1] == 0) && (board[rowP][colP - 1] != '0')) {
							board[rowP][colP - 1] = '0';
							if (squares > 0) {
								squares--;
							}
						}

						if (mines[rowP][colP + 1] == 1) {// check box board[rowP][colP + 1]
							count++;
						}
						else if ((mines[rowP][colP + 1] == 0) && (board[rowP][colP + 1] != '0')) {
							board[rowP][colP + 1] = '0';
							if (squares > 0) {
								squares--;
							}
						}

						if (mines[rowP + 1][colP - 1] == 1) {// check box near board[rowP + 1][colP - 1]
							count++;
						}
						else if ((mines[rowP + 1][colP - 1] == 0) && (board[rowP + 1][colP - 1] != '0')) {
							board[rowP + 1][colP - 1] = '0';
							if (squares > 0) {
								squares--;
							}
						}

						if (mines[rowP + 1][colP] == 1) {// check box board[rowP + 1][colP + 1]
							count++;
						}
						else if ((mines[rowP + 1][colP + 1] == 0) && (board[rowP + 1][colP + 1] != '0')) {
							board[rowP + 1][colP] = '0';
							if (squares > 0) {
								squares--;
							}
						}

						if (mines[rowP + 1][colP + 1] == 1) {// check box board[rowP + 1][colP + 1]
							count++;
						}
						else if ((mines[rowP + 1][colP + 1] == 0) && (board[rowP + 1][colP + 1] != '0')) {
							board[rowP + 1][colP + 1] = '0';
							if (squares > 0) {
								squares--;
							}
						}

						if ((count == 0) && (board[rowP][colP] == '-')) {//checks to see if number can change, and changes the display for "board[rowP][colP]"
							board[rowP][colP] = '0';
							if (squares > 0) {
								squares--;
							}
						}
						else if ((count == 1) && (board[rowP][colP] == '-')) {//checks to see if number can change, and changes the display for "board[rowP][colP]"
							board[rowP][colP] = '1';
							if (squares > 0) {
								squares--;
							}
						}
						else if ((count == 2) && (board[rowP][colP] == '-')) {//checks to see if number can change, and changes the display for "board[rowP][colP]"
							board[rowP][colP] = '2';
							if (squares > 0) {
								squares--;
							}
						}
						else if ((count == 3) && (board[rowP][colP] == '-')) {//checks to see if number can change, and changes the display for "board[rowP][colP]"
							board[rowP][colP] = '3';
							if (squares > 0) {
								squares--;
							}
						}
						else if ((count == 4) && (board[rowP][colP] == '-')) {//checks to see if number can change, and changes the display for "board[rowP][colP]"
							board[rowP][colP] = '4';
							if (squares > 0) {
								squares--;
							}
						}
						else if ((count == 5) && (board[rowP][colP] == '-')) {//checks to see if number can change, and changes the display for "board[rowP][colP]"
							board[rowP][colP] = '5';
							if (squares > 0) {
								squares--;
							}
						}
						else if ((count == 6) && (board[rowP][colP] == '-')) {//checks to see if number can change, and changes the display for "board[rowP][colP]"
							board[rowP][colP] = '6';
							if (squares > 0) {
								squares--;
							}
						}
					}
				}
			}
			print("board");
		}
		else if (action == 0) {
			cout << "In what row would you like to flag? ";
			cin >> rowP;

			cout << "In what column would you like to flag? ";
			cin >> colP;

			cout << "Your going to flag " << rowP << " " << colP << endl;
			colP--;
			rowP--;

			if (board[rowP][colP] == '-') {//changes value of "board[rowP][colP]" only if the value is '-' (meaning unchanged).
				board[rowP][colP] = 'F';
			}
			else {
				cout << endl << "You can't flag here" << endl;
			}

			if (mines[rowP][colP] == 1) {
				if (squares > 0) {
					squares--;
				}
			}

			print("board");
		}
	}
	cout << "You won!" << endl;
	return 0;
}

void print(string x) {
	if (x == "boardIn") { //intitailizes all the values of board to '-'
		for (int x = 0; x < 6; x++) {
			for (int y = 0; y < 6; y++) {
				board[x][y] = '-';
			}
		}
	}
	else if (x == "minesIn") { //initailizes all the values of mines to 0
		for (int x = 0; x < 6; x++) {
			for (int y = 0; y < 6; y++) {
				mines[x][y] = 0;
			}
		}
	}
	else if (x == "board") { //prints the board the user sees
		for (int x = 0; x < 6; x++) {
			for (int y = 0; y < 6; y++) {
				cout << board[x][y] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	else if (x == "assMines") { //assigns the values in the mine array to 
		for (int x = 0; x < 6; x++) {
			for (int y = 0; y < 6; y++) {
				int rowB = rand() % 6;
				int colB = rand() % 6;
				y = y - 1;
				while (y < 6) {
					if (mines[rowB][colB] == 0) {
						mines[rowB][colB] = 1;
					}
					else {
						y++;
					}
				}
			}
		}
	}
	else if (x == "mines") { // prints the mine pattern to console
		for (int x = 0; x < 6; x++) {
			for (int y = 0; y < 6; y++) {
				cout << mines[x][y] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}