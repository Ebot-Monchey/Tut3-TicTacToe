#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main() {
	TicTacToe game;
	cout << "Tic Tac Toe *** Enter -1 to quit" << endl << endl;
	game.print();
	cout << endl;
	int playerTurn = 1;			// Which player's turn it currently is
	int row, col;				// The row and column representing a move on the board

	while (true) {
		cout << "Player " << playerTurn << " Enter the row: ";
		cin >> row;
		if (row == -1) {
			break;
		}
		row--;			// 0 indexing of arrays

		cout << "Player " << playerTurn << " Enter the col: ";
		cin >> col;
		if (col == -1) {
			break;
		}
		col--;			// 0 indexing of arrays

		bool valid = game.move(playerTurn, row, col);
		if (!valid) {
			cout << "Invalid move" << endl;
			cout << endl;
			game.print();
			cout << endl;
		}
		else {
			int gameStatus = game.isWon();
			if (gameStatus == 0) {
				// game still in progress. switch turns
				playerTurn = playerTurn == 1 ? 2 : 1;
				cout << endl;
				game.print();
				cout << endl;
			}
			else if (gameStatus == 3) {
				game.print();
				cout << "Game drawn!" << endl << endl;
				game.restart();
				game.print();
				playerTurn = 1;
			}
			else {
				cout << endl;
				game.print();
				cout << "Player " << gameStatus << " won!" << endl << endl;
				game.restart();
				game.print();
				cout << endl;
				playerTurn = 1;
			}
		}
	}

	system("pause");
	return 0;
}