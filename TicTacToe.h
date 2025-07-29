class TicTacToe
{
public:
	TicTacToe();

	void printBoard(char board[3][3]);

	void mode();
	void player_player();
	void player1(char piece[3][3]);
	void player2(char piece[3][3]);
	void player_computer();
	void common();
	void blindMultifacetedPlaying();
	void blind_computer(char board[3][3], int record[9][2], int steps);
	void blind_player(char board[3][3], int record[9][2], int steps, int player_not_beated);

	bool checkX(char board[3][3]);
	bool checkO(char board[3][3]);
	bool win(char board[3][3]);
	bool tie(char board[3][3]);

	void blockUp(char board[3][3]);
	void fill(char board[3][3]);

	void player(char board[3][3], int record[9][2], int steps);
	void computer(char board[3][3], int record[9][2], int steps);

};
