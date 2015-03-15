#include <iostream>
#include "TicTacToe.h"

TicTacToe::TicTacToe() {
	restart();
}

void TicTacToe::restart() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = 0;
		}
	}
}

bool TicTacToe::move(int p, int row, int col) {
	if (board[row][col] != 0) {
		return false;
	}
	else {
		board[row][col] = p;
		return true;
	}
}

void TicTacToe::print() {
	using namespace std;
	for (int i = 0; i < 7; i++) {
		cout << "-";
	}
	cout << endl;
	for (int r = 0; r < 3; r++) {
		cout << "|";
		for (int c = 0; c < 3; c++) {
			if (board[r][c] == 0) {
				// Place an empty slot
				cout << " ";
			}
			else if (board[r][c] == 1) {
				// Place an X
				cout << "X";
			}
			else {
				// Place an 0
				cout << "0";
			}
			cout << "|";
		}
		cout << endl;
		for (int i = 0; i < 7; i++) {
			cout << "-";
		}
		cout << endl;
	}
}

int TicTacToe::isWon() {
	int p1, p2;			// Stores the number of times player 1 or 2 token appear in the row or column
	p1 = p2 = 0;

	// determine if a player won by checking all rows
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			if (board[r][c] == 1) {
				p1++;
			}
			else if (board[r][c] == 2) {
				p2++;
			}
			else {
				p1 = p2 = 0;
				break;		// stop checking this row, no winner
			}
		}
		if (p1 == 3) {
			return 1;
		}
		else if (p2 == 3) {
			return 2;
		}
		else {
			p1 = p2 = 0;
		}
	}
	// determine if a player won by checking all columns
	for (int c = 0; c < 3; c++) {
		for (int r = 0; r < 3; r++) {
			if (board[r][c] == 1) {
				p1++;
			}
			else if (board[r][c] == 2) {
				p2++;
			}
			else {
				p1 = p2 = 0;
				break;		// stop checking this column, no winner
			}
		}
		if (p1 == 3) {
			return 1;
		}
		else if (p2 == 3) {
			return 2;
		}
		else {
			p1 = p2 = 0;
		}
	}
	// determine if a player won by checking diagonals
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && (board[1][1]!=0)) {
		// diagonal going bottom-right has winner
		return board[1][1];
	}
	else if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]) && (board[1][1] != 0)) {
		// diagonal going top-right has winner
		return board[1][1];
	}
	else {
		// No winners at all.. check if game is in progress
		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 3; c++) {
				if (board[r][c] == 0) {
					return 0;	// game is still in progress
				}
			}
		}
		return 3;		// game is a draw
	}
	
}