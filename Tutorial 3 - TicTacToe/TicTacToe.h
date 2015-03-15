#ifndef TICTACTOE_H
#define TICTACTOE_H
	class TicTacToe {
	private:
		int board[3][3] = {};		// 0 represents empty, 1 represents player 1, and 2 represents player 2

	public:
		TicTacToe();
		/*
		 * Resets the board.
		 */
		void restart();
		/*
		 * Sets the move on the board if it is valid.
		 * p - 1 represents player 1 and 2 player 2.
		 */
		bool move(int p, int row, int col);
		/*
		 * Prints out the board as it currently is.
		 */
		void print();
		/*
		 * Determines whether the game has been won.
		 * Returns 0 if the game is still in progress
		 * Returns 1 if player 1 won the game
		 * Returns 2 if player 2 won the game
		 * Returns 3 if the game is still in progress
		 */
		int isWon();
	};
#endif