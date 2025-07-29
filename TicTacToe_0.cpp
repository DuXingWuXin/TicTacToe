#include <iostream>
#include <ctime>
#include <windows.h>
#include "TicTacToe.h"
using namespace std;

TicTacToe::TicTacToe()
{
}

bool TicTacToe::win(char piece[3][3])
{
	if (piece[0][0] != ' ' && piece[0][0] == piece[1][1] &&
		piece[0][0] == piece[2][2])
		return true;
	if (piece[2][0] != ' ' && piece[2][0] ==
		piece[1][1] && piece[2][0] == piece[0][2])
		return true;
	// check for win in X

	for (int a = 0; a < 3; a++)
		if (piece[a][0] != ' ' && piece[a][0] ==
			piece[a][1] && piece[a][0] == piece[a][2])
			return true;
	// check for win in rows

	for (int a = 0; a < 3; a++)
		if (piece[0][a] != ' ' && piece[0][a] ==
			piece[1][a] && piece[0][a] == piece[2][a])
			return true;
	// check for win in columns

	return false;
}

bool TicTacToe::tie(char piece[3][3])
{
	if (piece[0][0] != ' ' && piece[0][1] != ' ' && piece[0][2] != ' ' &&
		piece[1][0] != ' ' && piece[1][1] != ' ' && piece[1][2] != ' ' &&
		piece[2][0] != ' ' && piece[2][1] != ' ' && piece[2][2] != ' ')
		return true;
	else
		return false;
}

bool TicTacToe::checkX(char piece[3][3])
{
	if ((piece[2][2] == ' ' && piece[0][0] == piece[1][1] && piece[0][0] == 'X') ||
		(piece[1][1] == ' ' && piece[0][0] == piece[2][2] && piece[0][0] == 'X') ||
		(piece[0][0] == ' ' && piece[1][1] == piece[2][2] && piece[1][1] == 'X'))
		return true;
	if ((piece[0][2] == ' ' && piece[2][0] == piece[1][1] && piece[1][1] == 'X') ||
		(piece[1][1] == ' ' && piece[2][0] == piece[0][2] && piece[0][2] == 'X') ||
		(piece[2][0] == ' ' && piece[1][1] == piece[0][2] && piece[0][2] == 'X'))
		return true;
	// check in X

	for (int a = 0; a < 3; a++)
		if ((piece[a][0] == ' ' && piece[a][1] == piece[a][2] && piece[a][2] == 'X') ||
			(piece[a][1] == ' ' && piece[a][0] == piece[a][2] && piece[a][2] == 'X') ||
			(piece[a][2] == ' ' && piece[a][0] == piece[a][1] && piece[a][1] == 'X'))
			return true;
	// check in rows

	for (int a = 0; a < 3; a++)
		if ((piece[0][a] == ' ' && piece[1][a] == piece[2][a] && piece[2][a] == 'X') ||
			(piece[1][a] == ' ' && piece[0][a] == piece[2][a] && piece[2][a] == 'X') ||
			(piece[2][a] == ' ' && piece[0][a] == piece[1][a] && piece[2][a] == 'X'))
			return true;
	// check in columns

	return false;
}

bool TicTacToe::checkO(char piece[3][3])
{
	if ((piece[2][2] == ' ' && piece[0][0] == piece[1][1] && piece[0][0] == 'O') ||
		(piece[1][1] == ' ' && piece[0][0] == piece[2][2] && piece[0][0] == 'O') ||
		(piece[0][0] == ' ' && piece[1][1] == piece[2][2] && piece[1][1] == 'O'))
		return true;
	if ((piece[0][2] == ' ' && piece[2][0] == piece[1][1] && piece[1][1] == 'O') ||
		(piece[1][1] == ' ' && piece[2][0] == piece[0][2] && piece[0][2] == 'O') ||
		(piece[2][0] == ' ' && piece[1][1] == piece[0][2] && piece[0][2] == 'O'))
		return true;
	// check in X

	for (int a = 0; a < 3; a++)
		if ((piece[a][0] == ' ' && piece[a][1] == piece[a][2] && piece[a][2] == 'O') ||
			(piece[a][1] == ' ' && piece[a][0] == piece[a][2] && piece[a][2] == 'O') ||
			(piece[a][2] == ' ' && piece[a][0] == piece[a][1] && piece[a][1] == 'O'))
			return true;
	// check in rows

	for (int a = 0; a < 3; a++)
		if ((piece[0][a] == ' ' && piece[1][a] == piece[2][a] && piece[2][a] == 'O') ||
			(piece[1][a] == ' ' && piece[0][a] == piece[2][a] && piece[2][a] == 'O') ||
			(piece[2][a] == ' ' && piece[0][a] == piece[1][a] && piece[2][a] == 'O'))
			return true;
	// check in columns

	return false;
}

void TicTacToe::blockUp(char piece[3][3]) //堵
{
	int count = 1;
	for (int a = 0;a < 3;a++)
	{
		if ((piece[a][0] == piece[a][1] && piece[a][0] == 'X') ||
			(piece[a][0] == piece[a][2] && piece[a][0] == 'X') ||
			(piece[a][1] == piece[a][2] && piece[a][1] == 'X'))
			for (int b = 0;b < 3;b++)
				if (piece[a][b] == ' ' && count == 1)
				{
					piece[a][b] = 'O';
					cout << "Computer: " << a + 1 << " " << b + 1 << " \n\n";
					count++;
				}//堵行
	}

	for (int a = 0;a < 3;a++)
	{
		if ((piece[0][a] == piece[1][a] && piece[0][a] == 'X') ||
			(piece[0][a] == piece[2][a] && piece[0][a] == 'X') ||
			(piece[1][a] == piece[2][a] && piece[1][a] == 'X'))
			for (int b = 0;b < 3;b++)
			{
				if (piece[b][a] == ' ' && count == 1)
				{
					piece[b][a] = 'O';
					cout << "Computer:" << b + 1 << " " << a + 1 << " \n\n";
					count++;
				}//堵列
			}
	}

	if ((piece[0][0] == piece[1][1] && piece[0][0] == 'X') ||
		(piece[0][0] == piece[2][2] && piece[0][0] == 'X') ||
		(piece[1][1] == piece[2][2] && piece[1][1] == 'X'))
		for (int a = 0;a < 3;a++)
		{
			if (piece[a][a] == ' ' && count == 1)
			{
				piece[a][a] = 'O';
				cout << "Computer:" << a + 1 << " " << a + 1 << " \n\n";
				count++;
			}//堵左斜
		}
	if ((piece[2][0] == piece[1][1] && piece[2][0] == 'X') ||
		(piece[2][0] == piece[0][2] && piece[2][0] == 'X') ||
		(piece[1][1] == piece[0][2] && piece[0][2] == 'X'))
	{
		if (piece[2][0] == ' ' && count == 1)
		{
			piece[2][0] = 'O';
			cout << "Computer: 3 1\n\n";
			count++;
		}
		else if (piece[0][2] == ' ' && count == 1)
		{
			piece[0][2] = 'O';
			cout << "Computer: 1 3\n\n";
			count++;
		}
		else if (piece[1][1] == ' ' && count == 1)
		{
			piece[1][1] = 'O';
			cout << "Computer: 2 2\n\n";
			count++;
		}//堵右斜
	}
}

void TicTacToe::fill(char piece[3][3]) //补
{
	int count = 1;
	for (int a = 0;a < 3;a++)
		if ((piece[a][0] == piece[a][1] && piece[a][0] == 'O') ||
			(piece[a][0] == piece[a][2] && piece[a][0] == 'O') ||
			(piece[a][1] == piece[a][2] && piece[a][1] == 'O'))
			for (int c = 0;c < 3;c++)
			{
				if (piece[a][c] == ' ' && count == 1)
				{
					piece[a][c] = 'O';
					cout << "Computer: " << a + 1 << " " << c + 1 << " \n\n";
					count++;
				}//补行
			}
	for (int a = 0;a < 3;a++)
		if ((piece[0][a] == piece[1][a] && piece[0][a] == 'O') ||
			(piece[0][a] == piece[2][a] && piece[0][a] == 'O') ||
			(piece[1][a] == piece[2][a] && piece[1][a] == 'O'))
			for (int c = 0;c < 3;c++)
			{
				if (piece[c][a] == ' ' && count == 1)
				{
					piece[c][a] = 'O';
					cout << "Computer: " << c + 1 << " " << a + 1 << " \n\n";
					count++;
				}//补列
			}
	if ((piece[0][0] == piece[1][1] && piece[0][0] == 'O') ||
		(piece[0][0] == piece[2][2] && piece[0][0] == 'O') ||
		(piece[1][1] == piece[2][2] && piece[1][1] == 'O'))
		for (int c = 0;c < 3;c++)
		{
			if (piece[c][c] == ' ' && count == 1)
			{
				piece[c][c] = 'O';
				cout << "Computer:" << c + 1 << " " << c + 1 << " \n\n";
				count++;
			}//补左斜
		}
	if ((piece[2][0] == piece[1][1] && piece[2][0] == 'O') ||
		(piece[2][0] == piece[0][2] && piece[2][0] == 'O') ||
		(piece[1][1] == piece[0][2] && piece[0][2] == 'O'))
	{
		if (piece[2][0] == ' ' && count == 1)
		{
			piece[2][0] = 'O';
			cout << "Computer: 3 1\n\n";
			count++;
		}
		else if (piece[0][2] == ' ' && count == 1)
		{
			piece[0][2] = 'O';
			cout << "Computer: 1 3\n\n";
			count++;
		}
		else if (piece[1][1] == ' ' && count == 1)
		{
			piece[1][1] = 'O';
			cout << "Computer: 2 2\n\n";
			count++;
		}//补右斜
	}
}


void TicTacToe::player(char piece[3][3], int record[9][2], int steps) //玩家的棋子为“X”
{
	int x, y;
	cout << "player1 : ";
	cin >> x >> y;
	record[steps - 1][0] = x;
	record[steps - 1][1] = y;

	while (piece[x - 1][y - 1] != ' ')
	{
		cout << "Wrong input. Please input again.\n";
		cout << "player1 : ";
		cin >> x >> y;
	}

	piece[x - 1][y - 1] = 'X';

	cout << "\n";
}

void TicTacToe::computer(char piece[3][3], int record[9][2], int steps) //电脑的棋子为“O”
{
	int x = 0, y = 0;

	srand(static_cast<unsigned int>(time(0)));
	int i = rand() % 2;
	int j = rand() % 2;

	int count = 1;

	switch (steps)
	{
	case 1://电脑先手
		if (i == 1 && j == 1)
		{
			piece[1][1] = 'O';
			record[0][0] = 1;
			record[0][1] = 1;
			cout << "Computer: 2 2\n\n";//电脑落子于中心
		}
		else
		{
			x = (i == 1) ? 2 : 0;
			y = (j == 1) ? 2 : 0;
			piece[x][y] = 'O';
			record[0][0] = x + 1;
			record[0][1] = y + 1;
			cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n";//电脑落子于角落
		}
		break;

	case 2://玩家先手
		if (piece[1][1] == 'X') //玩家第一步落于中心
		{
			x = (i == 1) ? 2 : 0;
			y = (j == 1) ? 2 : 0;
			piece[x][y] = 'O';
			record[0][0] = x + 1;
			record[0][1] = y + 1;
			cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n";//电脑落子于角落
		}
		else //玩家第一步落于其他位置
		{
			piece[1][1] = 'O';
			record[0][0] = 2;
			record[0][1] = 2;
			cout << "Computer: 2 2\n\n"; //电脑落子于中心
		}
		break;

	case 3://电脑先手
		if (piece[1][1] == 'O') //电脑第一步落于中心
		{
			if (piece[0][1] == 'X' || piece[1][0] == 'X' || piece[1][2] == 'X' || piece[2][1] == 'X') //玩家第二步落于边缘
			{
				if (count == 1)
				{
					x = (i == 1) ? 2 : 0;
					y = (j == 1) ? 2 : 0;
					piece[x][y] = 'O';
					record[2][0] = x + 1;
					record[2][1] = y + 1;
					cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //电脑第三步落于角落
					count++;
				}
			}
			else //玩家第二步落于角落
			{
				for (int a = 0;a < 3;a = a + 2)
					for (int b = 0;b < 3;b = b + 2)
						if (piece[a][b] == 'X' && count == 1)
						{
							int x = (a == 0) ? a + 2 : a - 2;
							int y = (b == 0) ? b + 2 : b - 2;
							piece[x][y] = 'O';
							record[2][0] = x + 1;
							record[2][1] = y + 1;
							cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //电脑第三步落于玩家的对角
							count++;
						}
			}
		}
		else //电脑第一步落于角落
		{
			if (piece[1][1] == 'X') //玩家第二步落于中心
			{
				for (int a = 0;a < 3;a = a + 2)
					for (int b = 0;b < 3;b = b + 2)
					{
						if (piece[a][b] == 'O' && count == 1)
						{
							int x = (a == 0) ? a + 2 : a - 2;
							int y = (b == 0) ? b + 2 : b - 2;
							piece[x][y] = 'O';
							record[2][0] = x + 1;
							record[2][1] = y + 1;
							cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //电脑第三步落于第一步的对角
							count++;
						}
					}
			}
			else //玩家第二步落于边缘或角落
			{
				for (int a = 0;a < 3;a = a + 2)
					for (int b = 0;b < 3;b = b + 2)
					{
						if (piece[a][b] == 'O' && count == 1)
						{
							int x = a;
							int y = (b == 0) ? b + 2 : b - 2;
							if (piece[x][y] == ' ')
							{
								piece[x][y] = 'O';
								record[2][0] = x + 1;
								record[2][1] = y + 1;
								cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //电脑第三步落于第一步同一行的角落
								count++;
							}
							else
							{
								x = (a == 0) ? a + 2 : a - 2;
								y = b;
								piece[x][y] = 'O';
								record[2][0] = x + 1;
								record[2][1] = y + 1;
								cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //电脑第三步落于第一步同一列的角落
								count++;
							}
						}
					}
			}
		}

		break;

	case 4://玩家先手
		if (piece[1][1] == 'X')
			//玩家第一步落于中心，电脑第二步必落于角落
		{
			//玩家第三步落于电脑第二步的对角
			for (int a = 0;a < 3;a = a + 2)
				for (int b = 0;b < 3;b = b + 2)
				{
					if (piece[a][b] == 'O')
					{
						int i = (a == 0) ? 2 : 0;
						int j = (b == 0) ? 2 : 0;
						if (piece[i][j] == 'X' && count == 1)
						{
							piece[i][b] = 'O';
							cout << "Computer: " << i + 1 << " " << b + 1 << "\n\n"; //电脑落于第三步同一行的角落
							count++;
						}
					}
				}
			blockUp(piece);
		}
		else if ((record[0][0] == 1 && record[0][1] == 1) ||
			(record[0][0] == 1 && record[0][1] == 3) ||
			(record[0][0] == 3 && record[0][1] == 1) ||
			(record[0][0] == 3 && record[0][1] == 3))
			//玩家第一步落于角落，电脑第二步必落于中心
		{
			if ((piece[0][0] == piece[2][2] && piece[0][0] == 'X') ||
				(piece[0][2] == piece[2][0] && piece[0][2] == 'X')) //玩家第三步在第一步的对角
			{
				srand(static_cast<unsigned int>(time(0)));
				int i = rand() % 3;
				if (i == 1 && count == 1)
				{
					int j = rand() % 2;
					y = (j == 1) ? 2 : 0;
					piece[1][y] = 'O';
					cout << "Computer: 2 " << y + 1 << "\n\n";
					count++;
				}
				else if (count == 1)
				{
					piece[i][1] = 'O';
					cout << "Computer: " << i + 1 << " 2\n\n";
					count++;
				}
				//电脑第四步任选第二行或第二列一个位置落子
			}
			else if ((piece[0][0] == 'X' && (piece[1][2] == 'X' || piece[2][1] == 'X')) ||
				(piece[0][2] == 'X' && (piece[1][0] == 'X' || piece[2][1] == 'X')) ||
				(piece[2][0] == 'X' && (piece[0][1] == 'X' || piece[1][2] == 'X')) ||
				(piece[2][2] == 'X' && (piece[0][1] == 'X' || piece[1][0] == 'X')))
				//玩家第三步落于与第一步不同行且不同列的边缘
			{
				if (piece[1][0] == ' ' && piece[1][2] == ' ' && count == 1)
				{
					piece[1][0] = 'O';
					cout << "Computer: 2 1\n\n"; //第二行有两个空时，电脑落于第二行
					count++;
				}
				else if (piece[0][1] == ' ' && piece[2][1] == ' ' && count == 1)
				{
					piece[0][1] = 'O';
					cout << "Computer: 1 2\n\n"; //第二列有两个空时，电脑落于第二列
					count++;
				}
			}
			else //玩家第三步与第一步同行或同列
				blockUp(piece);
		}
		else if ((record[0][0] == 1 && record[0][1] == 2) ||
			(record[0][0] == 2 && record[0][1] == 1) ||
			(record[0][0] == 2 && record[0][1] == 3) ||
			(record[0][0] == 3 && record[0][1] == 2))
			//玩家第一步落于边缘，电脑第二步必落于中心
		{
			if ((piece[0][1] == 'X' && piece[2][1] == 'X') ||
				piece[1][0] == 'X' && piece[1][2] == 'X')
				//玩家第三步落于第二步同行或同列的边缘
			{
				if (count == 1)
				{
					x = (i == 1) ? 2 : 0;
					y = (j == 1) ? 2 : 0;
					piece[x][y] = 'O';
					cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //电脑第四步落于任意一个角落
					count++;
				}
			}
			else if ((piece[0][1] == 'X' && (piece[2][0] == 'X' || piece[2][2] == 'X')) ||
				(piece[1][0] == 'X' && (piece[0][2] == 'X' || piece[2][2] == 'X')) ||
				(piece[1][2] == 'X' && (piece[0][0] == 'X' || piece[2][0] == 'X')) ||
				(piece[2][1] == 'X' && (piece[0][0] == 'X' || piece[0][2] == 'X')))
				//玩家第三步落于与第一步不同行且不同列的角落
			{
				if (piece[1][0] == ' ' && piece[1][2] == ' ' && count == 1)
				{
					piece[1][0] = 'O';
					cout << "Computer: 2 1\n\n"; //第二行有两个空时，电脑落于第二行
					count++;
				}
				else if (piece[0][1] == ' ' && piece[2][1] == ' ' && count == 1)
				{
					piece[0][1] = 'O';
					cout << "Computer: 1 2\n\n"; //第二列有两个空时，电脑落于第二列
					count++;
				}
			}
		}
		else //玩家第三步与第一步同行或同列
			blockUp(piece);

		break;

	case 5://电脑先手
		if (piece[1][1] == 'O') //电脑第一步落于中心
		{
			if (piece[0][1] == 'X' || piece[1][0] == 'X' || piece[1][2] == 'X' || piece[2][1] == 'X')
				//玩家第二步落于边缘,电脑第三步必落于任意角落，玩家第四步需要堵“斜三”
			{
				//玩家第四步没有堵“斜三”
				if (checkO(piece))
				{
					fill(piece);
				}
				//玩家第四步堵了“斜三”
				else if (piece[1][0] == 'X' || piece[1][2] == 'X') //玩家第二步落于第二行的边缘
				{
					for (int a = 0;a < 3;a = a + 2)
						for (int b = 0;b < 3;b = b + 2)
							if (piece[a][b] == 'O')
							{
								int x = a;
								int y = (b == 0) ? b + 2 : b - 2;
								piece[x][y] = 'O';
								record[4][0] = x + 1;
								record[4][1] = y + 1;
								cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //电脑第五步落于第三步同一行的角落
							}
				}
				else if (piece[0][1] == 'X' || piece[2][1] == 'X') //玩家第二步落于第二列的边缘
				{
					for (int a = 0;a < 3;a = a + 2)
						for (int b = 0;b < 3;b = b + 2)
							if (piece[a][b] == 'O')
							{
								int x = (a == 0) ? a + 2 : a - 2;
								int y = b;
								piece[x][y] = 'O';
								record[4][0] = x + 1;
								record[4][1] = y + 1;
								cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //电脑第五步落于第三步同一列的角落
							}
				}
			}
			else if (piece[0][0] == 'X' || piece[0][2] == 'X' || piece[2][0] == 'X' || piece[2][2] == 'X')
				//玩家第二步落于角落，电脑第三步必落于其对角，此时玩家有三种可能
			{
				if (piece[0][1] == 'X') //玩家第四步落于第一行的边缘
				{
					if (checkO(piece))
					{
						fill(piece);
					}
					else if (piece[0][0] == 'X' || piece[0][2] == 'X') //玩家第二步落于第一行
					{
						for (int b = 0;b < 3;b++)
							if (piece[0][b] == ' ')
							{
								piece[0][b] = 'O';
								record[4][0] = 1;
								record[4][1] = b + 1;
								cout << "Computer: 1 " << b + 1 << "\n\n"; //电脑第五步堵“横三”
							}
					}
					else if (piece[2][0] == 'X' || piece[2][2] == 'X') //玩家第二步落于第三行
					{
						for (int b = 0;b < 3;b = b + 2)
							if (piece[2][b] == 'X')
							{
								y = (b == 0) ? b + 2 : b - 2;
								piece[2][y] = 'O';
								record[4][0] = 3;
								record[4][1] = y + 1;
								cout << "Computer: 3 " << y + 1 << "\n\n"; //电脑第五步落于玩家第二步同一行的角落
							}
					}
				}
				else if (piece[1][0] == 'X' || piece[1][2] == 'X') //玩家第四步落于第二行的边缘
				{
					if (checkO(piece))
					{
						fill(piece);
					}
					else if (piece[0][0] == 'X' || piece[0][2] == 'X') //玩家第二步落于第一行
					{
						for (int b = 0;b < 3;b = b + 2)
							if (piece[0][b] == 'X')
							{
								piece[2][b] = 'O';
								record[4][0] = 3;
								record[4][1] = b + 1;
								cout << "Computer: 3 " << b + 1 << "\n\n"; //电脑第五步落于玩家第二步同一列的角落
							}
					}
					else if (piece[2][0] == 'X' || piece[2][2] == 'X') //玩家第二步落于第三行
					{
						for (int b = 0;b < 3;b = b + 2)
							if (piece[2][b] == 'X')
							{
								piece[0][b] = 'O';
								record[4][0] = 1;
								record[4][1] = b + 1;
								cout << "Computer: 1 " << b + 1 << "\n\n"; //电脑第五步落于玩家第二步同一列的角落
							}
					}
				}
				else if (piece[2][1] == 'X') //玩家第四步落于第三行的边缘
				{
					if (checkO(piece))
					{
						fill(piece);
					}
					else if (piece[0][0] == 'X' || piece[0][2] == 'X') //玩家第二步落于第一行
					{
						for (int b = 0;b < 3;b = b + 2)
							if (piece[0][b] == 'X')
							{
								piece[2][b] = 'O';
								record[4][0] = 3;
								record[4][1] = b + 1;
								cout << "Computer: 3 " << b + 1 << "\n\n"; //电脑第五步落于玩家第二步同一列的角落
							}
					}
					else if (piece[2][0] == 'X' || piece[2][2] == 'X') //玩家第二步落于第三行
					{
						for (int b = 0;b < 3;b = b + 2)
							if (piece[2][b] == ' ')
							{
								piece[2][b] = 'O';
								record[4][0] = 3;
								record[4][1] = b + 1;
								cout << "Computer: 3 " << b + 1 << "\n\n"; //电脑第五步落于玩家第二步同一行的角落
							}
					}
				}
				else //玩家第四步落于角落
					blockUp(piece);
			}
		}
		else //电脑第一步落于角落
		{
			if (piece[1][1] == 'X')
				//玩家第二步落于中心，此时电脑第三步在第一步的对角
			{
				if (checkO(piece))
				{
					fill(piece);
				}
				else if (piece[0][1] == 'X' || piece[1][0] == 'X' || piece[1][2] == 'X' || piece[2][1] == 'X') //玩家第四步落于边缘
				{
					blockUp(piece); //电脑第五步堵“竖三”
				}
				else if (piece[0][0] == 'X' || piece[0][2] == 'X' || piece[2][0] == 'X' || piece[2][2] == 'X') //玩家第四步落于角落
				{
					for (int a = 0;a < 3;a = a + 2)
						for (int b = 0;b < 3;b = b + 2)
							if (piece[a][b] == 'X')
							{
								int x = (a == 0) ? a + 2 : a - 2;
								int y = (b == 0) ? b + 2 : b - 2;
								piece[x][y] = 'O';
								record[4][0] = x + 1;
								record[4][1] = y + 1;
								cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //电脑第五步落于玩家第四步的对角
							}
				}
			}
			else
				//玩家第二步落于其他地方,此时电脑第三步落于第一步同行或同列的角落
			{
				if (checkO(piece)) //玩家第四步没有堵“行三”或“竖三”
				{
					fill(piece);
				}
				else //玩家第四步堵“行三”或“竖三”
				{
					srand(static_cast<unsigned int>(time(0)));
					int i1 = rand() % 2;
					int j1 = rand() % 2;
					if (i1 == 1 && j1 == 1)
					{
						piece[1][1] = 'O';
						record[4][0] = 2;
						record[4][1] = 2;
						cout << "Computer: 2 2\n\n"; //电脑第五步落于中心
					}
					else
					{
						if (record[0][0] == 1 && record[0][1] == 1) //电脑第一步落于1，1
						{
							piece[2][2] = 'O';
							record[4][0] = 3;
							record[4][1] = 3;
							cout << "Computer: 3 3\n\n";
						}
						else if (record[0][0] == 1 && record[0][1] == 3) //电脑第一步落于1，3
						{
							piece[2][0] = 'O';
							record[4][0] = 3;
							record[4][1] = 1;
							cout << "Computer: 3 1\n\n";
						}
						else if (record[0][0] == 3 && record[0][1] == 1) //电脑第一步落于3，1
						{
							piece[0][2] = 'O';
							record[4][0] = 1;
							record[4][1] = 3;
							cout << "Computer: 1 3\n\n";
						}
						else if (record[0][0] == 3 && record[0][1] == 3) //电脑第一步落于3，3
						{
							piece[0][0] = 'O';
							record[4][0] = 1;
							record[4][1] = 1;
							cout << "Computer: 1 1\n\n";
						}
					} //电脑第五步落于第一步的对角
				}
			}
		}

		break;

	case 6://玩家先手
		if (piece[1][1] == 'X') //玩家第一步落于中心
		{
			if (checkO(piece))
				fill(piece);
			else
				blockUp(piece);
		}
		else if (piece[1][1] == 'O') //玩家第一步没落于中心
		{
			if (checkO(piece))
				fill(piece);
			else if (checkX(piece))
				blockUp(piece);
			else
			{
				if (piece[1][0] == ' ')
				{
					piece[1][0] = 'O';
					cout << "Computer: 2 1\n\n"; //电脑第六步落于第二行
				}
				else if (piece[1][2] == ' ')
				{
					piece[1][2] = 'O';
					cout << "Computer: 2 3\n\n"; //电脑第六步落于第二行
				}
			}
		}
		break;

	case 7://电脑先手
		if (checkO(piece))
			fill(piece);
		else if (checkX(piece))
			blockUp(piece);
		else
		{
			srand((unsigned)time(NULL));
			x = rand() % 3;
			y = rand() % 3;
			while (piece[x][y] != ' ')
			{
				x = rand() % 3;
				y = rand() % 3;
			}
			piece[x][y] = 'O';
			cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //电脑第七步随意落子
		}

		break;

	case 8://玩家先手
		if (checkO(piece))
			fill(piece);
		else if (checkX(piece))
			blockUp(piece);
		else
		{
			srand((unsigned)time(NULL));
			x = rand() % 3;
			y = rand() % 3;
			while (piece[x][y] != ' ')
			{
				x = rand() % 3;
				y = rand() % 3;
			}
			piece[x][y] = 'O';
			cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //电脑第八步随意落子
		}
		break;

	case 9://电脑先手
		for (int a = 0;a < 3;a++)
			for (int b = 0;b < 3;b++)
				if (piece[a][b] == ' ')
				{
					piece[a][b] = 'O';
					cout << "Computer:" << a + 1 << " " << b + 1 << " \n\n";
				}

		break;

	}
}

