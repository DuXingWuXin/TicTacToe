#include <iostream>
#include <ctime>
#include <windows.h>
#include "TicTacToe.h"
using namespace std;

void TicTacToe::printBoard(char piece[3][3])
{
	cout << "    1   2   3" << "\n" << endl;
	for (int i = 1;i <= 2;i++)
	{
		cout << i << "   ";
		for (int j = 1;j <= 2;j++)
		{
			cout << piece[i - 1][j - 1] << " | ";
		}
		cout << piece[i - 1][2] << endl;
		cout << "   ---|---|---" << endl;
	}
	cout << "3   " << piece[2][0] << " | " << piece[2][1] << " | " << piece[2][2] << "\n\n"
		<< "**************************************************************\n\n";
}

void TicTacToe::mode()
{
	int choice0;
	cout << "\t\t\t" << "#####  *  #####  #####   #     #####  #####  #####  #####\n";
	cout << "\t\t\t" << "  #    #  #        #    # #    #        #    #   #  #====\n";
	cout << "\t\t\t" << "  #    #  #        #   #####   #        #    #   #  #    \n";
	cout << "\t\t\t" << "  #    #  #####    #  #     #  #####    #    #####  #####\n";

	cout << "选择游戏模式：\n"
		<< "1：玩家VS玩家\n"
		<< "2：玩家VS电脑\n"
		<< "3：退出TicTacToe\n";
	cin >> choice0;

	switch (choice0)
	{
	case 1:
		system("cls");
		player_player();
		break;
	case 2:
		system("cls");
		player_computer();
		break;
	default:
		system("cls");
		break;
	}
}

void TicTacToe::player_player()
{
	char piece[3][3] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ', };
	printBoard(piece);

	for (int i = 0; i < 4;i++)
	{
		player1(piece);
		if (win(piece))
		{
			cout << "player1 wins!\n\n";
			break;
		}
		else if (tie(piece))
		{
			cout << "tie!\n\n";
			break;
		}
		player2(piece);
		if (win(piece))
		{
			cout << "player2 wins!\n\n";
			break;
		}
		else if (tie(piece))
		{
			cout << "tie!\n\n";
			break;
		}
	}
	if (!win(piece) && !tie(piece))
		player1(piece);

	int choice1;
	cout << "\n1、继续 \t 2、返回上一级\n";
	cin >> choice1;
	cout << endl;

	switch (choice1)
	{
	case 1:
		system("cls");
		player_player();
		break;
	default:
		system("cls");
		mode();
		break;
	}
}

void TicTacToe::player1(char piece[3][3])
{
	int x, y;
	cout << "player1 : ";
	cin >> x >> y;
	cout << endl;

	while (piece[x - 1][y - 1] != ' ')
	{
		cout << "player1 : ";
		cin >> x >> y;
	}
	piece[x - 1][y - 1] = 'X';

	printBoard(piece);
}

void TicTacToe::player2(char piece[3][3])
{
	int x, y;
	cout << "player2 : ";
	cin >> x >> y;
	cout << endl;

	while (piece[x - 1][y - 1] != ' ')
	{
		cout << "player2 : ";
		cin >> x >> y;
	}
	piece[x - 1][y - 1] = 'O';

	printBoard(piece);

	if (win(piece))
		cout << "player2 wins!\n\n";
	else if (tie(piece))
		cout << "tie!\n\n";
}


void TicTacToe::player_computer()
{
	int choice2;

	cout << "选择游戏模式：\n"
		<< "1、普通模式\n"
		<< "2、多面打模式（1 VS 5）\n"
		<< "3、返回上一级\n";
	cin >> choice2;

	switch (choice2)
	{
	case 1:
		system("cls");
		common();
		break;
	case 2:
		system("cls");
		blindMultifacetedPlaying();
		break;
	default:
		system("cls");
		mode();
		break;
	}

}

void TicTacToe::common()
{
	char board[3][3] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ', };
	int record[9][2] = { 0 };
	int first;
	cout << "选择先手或后手：先手（1），后手（2）  ";
	cin >> first;
	cout << "\n";

	printBoard(board);

	int steps = 1;
	if (first == 1)
		for (int a = 1;a <= 9;a++)
		{
			player(board, record, steps);
			printBoard(board);
			if (win(board))
			{
				cout << "Player wins!\n\n";
				break;
			}
			else if (tie(board))
			{
				cout << "Tie!\n\n";
				break;
			}
			steps++;

			computer(board, record, steps);
			printBoard(board);
			if (win(board))
			{
				cout << "Computer wins!\n\n";
				break;
			}
			else if (tie(board))
			{
				cout << "Tie!\n\n";
				break;
			}
			steps++;
		}
	else if (first == 2)
		for (int a = 1;a <= 9;a++)
		{
			computer(board, record, steps);
			printBoard(board);
			if (win(board))
			{
				cout << "Computer wins!\n\n";
				break;
			}
			else if (tie(board))
			{
				cout << "Tie!\n\n";
				break;
			}
			steps++;

			player(board, record, steps);
			printBoard(board);
			if (win(board))
			{
				cout << "Player wins!\n\n";
				break;
			}
			else if (tie(board))
			{
				cout << "Tie!\n\n";
				break;
			}
			steps++;
		}
	int choice3;
	cout << "\n1、继续 \t 2、返回上一级\n";
	cin >> choice3;
	cout << endl;

	switch (choice3)
	{
	case 1:
		system("cls");
		common();
		break;
	default:
		system("cls");
		player_computer();
		break;
	}
}

void TicTacToe::blindMultifacetedPlaying()
{
	char board1[3][3] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ', };
	char board2[3][3] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ', };
	char board3[3][3] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ', };
	char board4[3][3] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ', };
	char board5[3][3] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ', };

	int record1[9][2] = { 0 };
	int record2[9][2] = { 0 };
	int record3[9][2] = { 0 };
	int record4[9][2] = { 0 };
	int record5[9][2] = { 0 };

	TicTacToe T1, T2, T3, T4, T5;

	int player_not_beated = 0;

	int steps1 = 1, steps2 = 1, steps3 = 1, steps4 = 1, steps5 = 1;
	for (int a = 1;a <= 4;a++)
	{
		cout << "******************************对局1***************************\n";
		T1.blind_computer(board1, record1, steps1);
		steps1++;
		T1.blind_player(board1, record1, steps1, player_not_beated);
		steps1++;
		cout << "**************************************************************\n\n";

		cout << "******************************对局2***************************\n";
		T2.blind_computer(board2, record2, steps2);
		steps2++;
		T2.blind_player(board2, record2, steps2, player_not_beated);
		steps2++;
		cout << "**************************************************************\n\n";

		cout << "******************************对局3***************************\n";
		T3.blind_computer(board3, record3, steps3);
		steps3++;
		T3.blind_player(board3, record3, steps3, player_not_beated);
		steps3++;
		cout << "**************************************************************\n\n";

		cout << "******************************对局4***************************\n";
		T4.blind_computer(board4, record4, steps4);
		steps4++;
		T4.blind_player(board4, record4, steps4, player_not_beated);
		steps4++;
		cout << "**************************************************************\n\n";

		cout << "******************************对局5***************************\n";
		T5.blind_computer(board5, record5, steps5);
		steps5++;
		T5.blind_player(board5, record5, steps5, player_not_beated);
		steps5++;
		cout << "**************************************************************\n\n";

	}
	cout << "******************************对局1***************************\n";
	T1.blind_computer(board1, record1, steps1);
	cout << "**************************************************************\n\n";

	cout << "******************************对局2***************************\n";
	T2.blind_computer(board2, record2, steps2);
	cout << "**************************************************************\n\n";

	cout << "******************************对局3***************************\n";
	T3.blind_computer(board3, record3, steps3);
	cout << "**************************************************************\n\n";

	cout << "******************************对局4***************************\n";
	T4.blind_computer(board4, record4, steps4);
	cout << "**************************************************************\n\n";

	cout << "******************************对局5***************************\n";
	T5.blind_computer(board5, record5, steps5);
	cout << "**************************************************************\n\n";



	cout << "******************************对局1***************************\n\n";
	T1.printBoard(board1);

	cout << "******************************对局2***************************\n\n";
	T2.printBoard(board2);

	cout << "******************************对局3***************************\n\n";
	T3.printBoard(board3);

	cout << "******************************对局4***************************\n\n";
	T4.printBoard(board4);

	cout << "******************************对局5***************************\n\n";
	T5.printBoard(board5);

	cout << "Player isn't beated for " << player_not_beated << " times\n\n";

	if (player_not_beated == 5)  //多面打全赢的小彩蛋
		cout << "                                Wow!   恭喜你解锁“多面打大师”成就！！！       \n\n";

	int choice4;
	cout << "\n1、继续 \t 2、返回上一级\n";
	cin >> choice4;
	cout << endl;

	switch (choice4)
	{
	case 1:
		system("cls");
		blindMultifacetedPlaying();
		break;
	default:
		system("cls");
		player_computer();
		break;
	}
}

void TicTacToe::blind_computer(char board[3][3], int record[9][2], int steps)
{
	if (!win(board) && !tie(board))
	{
		computer(board, record, steps);
		if (win(board))
			cout << "Computer wins!\n\n";
		else if (tie(board))
			cout << "Tie!\n\n";
	}
}

void TicTacToe::blind_player(char board[3][3], int record[9][2], int steps, int player_not_beated)
{
	if (!win(board) && !tie(board))
	{
		player(board, record, steps);
		if (win(board))
		{
			cout << "Player wins!\n\n";
			player_not_beated++;
		}
		else if (tie(board))
		{
			cout << "Tie!\n\n";
			player_not_beated++;
		}
	}
}