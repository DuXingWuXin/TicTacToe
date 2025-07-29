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

void TicTacToe::blockUp(char piece[3][3]) //��
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
				}//����
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
				}//����
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
			}//����б
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
		}//����б
	}
}

void TicTacToe::fill(char piece[3][3]) //��
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
				}//����
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
				}//����
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
			}//����б
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
		}//����б
	}
}


void TicTacToe::player(char piece[3][3], int record[9][2], int steps) //��ҵ�����Ϊ��X��
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

void TicTacToe::computer(char piece[3][3], int record[9][2], int steps) //���Ե�����Ϊ��O��
{
	int x = 0, y = 0;

	srand(static_cast<unsigned int>(time(0)));
	int i = rand() % 2;
	int j = rand() % 2;

	int count = 1;

	switch (steps)
	{
	case 1://��������
		if (i == 1 && j == 1)
		{
			piece[1][1] = 'O';
			record[0][0] = 1;
			record[0][1] = 1;
			cout << "Computer: 2 2\n\n";//��������������
		}
		else
		{
			x = (i == 1) ? 2 : 0;
			y = (j == 1) ? 2 : 0;
			piece[x][y] = 'O';
			record[0][0] = x + 1;
			record[0][1] = y + 1;
			cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n";//���������ڽ���
		}
		break;

	case 2://�������
		if (piece[1][1] == 'X') //��ҵ�һ����������
		{
			x = (i == 1) ? 2 : 0;
			y = (j == 1) ? 2 : 0;
			piece[x][y] = 'O';
			record[0][0] = x + 1;
			record[0][1] = y + 1;
			cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n";//���������ڽ���
		}
		else //��ҵ�һ����������λ��
		{
			piece[1][1] = 'O';
			record[0][0] = 2;
			record[0][1] = 2;
			cout << "Computer: 2 2\n\n"; //��������������
		}
		break;

	case 3://��������
		if (piece[1][1] == 'O') //���Ե�һ����������
		{
			if (piece[0][1] == 'X' || piece[1][0] == 'X' || piece[1][2] == 'X' || piece[2][1] == 'X') //��ҵڶ������ڱ�Ե
			{
				if (count == 1)
				{
					x = (i == 1) ? 2 : 0;
					y = (j == 1) ? 2 : 0;
					piece[x][y] = 'O';
					record[2][0] = x + 1;
					record[2][1] = y + 1;
					cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //���Ե��������ڽ���
					count++;
				}
			}
			else //��ҵڶ������ڽ���
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
							cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //���Ե�����������ҵĶԽ�
							count++;
						}
			}
		}
		else //���Ե�һ�����ڽ���
		{
			if (piece[1][1] == 'X') //��ҵڶ�����������
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
							cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //���Ե��������ڵ�һ���ĶԽ�
							count++;
						}
					}
			}
			else //��ҵڶ������ڱ�Ե�����
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
								cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //���Ե��������ڵ�һ��ͬһ�еĽ���
								count++;
							}
							else
							{
								x = (a == 0) ? a + 2 : a - 2;
								y = b;
								piece[x][y] = 'O';
								record[2][0] = x + 1;
								record[2][1] = y + 1;
								cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //���Ե��������ڵ�һ��ͬһ�еĽ���
								count++;
							}
						}
					}
			}
		}

		break;

	case 4://�������
		if (piece[1][1] == 'X')
			//��ҵ�һ���������ģ����Եڶ��������ڽ���
		{
			//��ҵ��������ڵ��Եڶ����ĶԽ�
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
							cout << "Computer: " << i + 1 << " " << b + 1 << "\n\n"; //�������ڵ�����ͬһ�еĽ���
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
			//��ҵ�һ�����ڽ��䣬���Եڶ�������������
		{
			if ((piece[0][0] == piece[2][2] && piece[0][0] == 'X') ||
				(piece[0][2] == piece[2][0] && piece[0][2] == 'X')) //��ҵ������ڵ�һ���ĶԽ�
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
				//���Ե��Ĳ���ѡ�ڶ��л�ڶ���һ��λ������
			}
			else if ((piece[0][0] == 'X' && (piece[1][2] == 'X' || piece[2][1] == 'X')) ||
				(piece[0][2] == 'X' && (piece[1][0] == 'X' || piece[2][1] == 'X')) ||
				(piece[2][0] == 'X' && (piece[0][1] == 'X' || piece[1][2] == 'X')) ||
				(piece[2][2] == 'X' && (piece[0][1] == 'X' || piece[1][0] == 'X')))
				//��ҵ������������һ����ͬ���Ҳ�ͬ�еı�Ե
			{
				if (piece[1][0] == ' ' && piece[1][2] == ' ' && count == 1)
				{
					piece[1][0] = 'O';
					cout << "Computer: 2 1\n\n"; //�ڶ�����������ʱ���������ڵڶ���
					count++;
				}
				else if (piece[0][1] == ' ' && piece[2][1] == ' ' && count == 1)
				{
					piece[0][1] = 'O';
					cout << "Computer: 1 2\n\n"; //�ڶ�����������ʱ���������ڵڶ���
					count++;
				}
			}
			else //��ҵ��������һ��ͬ�л�ͬ��
				blockUp(piece);
		}
		else if ((record[0][0] == 1 && record[0][1] == 2) ||
			(record[0][0] == 2 && record[0][1] == 1) ||
			(record[0][0] == 2 && record[0][1] == 3) ||
			(record[0][0] == 3 && record[0][1] == 2))
			//��ҵ�һ�����ڱ�Ե�����Եڶ�������������
		{
			if ((piece[0][1] == 'X' && piece[2][1] == 'X') ||
				piece[1][0] == 'X' && piece[1][2] == 'X')
				//��ҵ��������ڵڶ���ͬ�л�ͬ�еı�Ե
			{
				if (count == 1)
				{
					x = (i == 1) ? 2 : 0;
					y = (j == 1) ? 2 : 0;
					piece[x][y] = 'O';
					cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //���Ե��Ĳ���������һ������
					count++;
				}
			}
			else if ((piece[0][1] == 'X' && (piece[2][0] == 'X' || piece[2][2] == 'X')) ||
				(piece[1][0] == 'X' && (piece[0][2] == 'X' || piece[2][2] == 'X')) ||
				(piece[1][2] == 'X' && (piece[0][0] == 'X' || piece[2][0] == 'X')) ||
				(piece[2][1] == 'X' && (piece[0][0] == 'X' || piece[0][2] == 'X')))
				//��ҵ������������һ����ͬ���Ҳ�ͬ�еĽ���
			{
				if (piece[1][0] == ' ' && piece[1][2] == ' ' && count == 1)
				{
					piece[1][0] = 'O';
					cout << "Computer: 2 1\n\n"; //�ڶ�����������ʱ���������ڵڶ���
					count++;
				}
				else if (piece[0][1] == ' ' && piece[2][1] == ' ' && count == 1)
				{
					piece[0][1] = 'O';
					cout << "Computer: 1 2\n\n"; //�ڶ�����������ʱ���������ڵڶ���
					count++;
				}
			}
		}
		else //��ҵ��������һ��ͬ�л�ͬ��
			blockUp(piece);

		break;

	case 5://��������
		if (piece[1][1] == 'O') //���Ե�һ����������
		{
			if (piece[0][1] == 'X' || piece[1][0] == 'X' || piece[1][2] == 'X' || piece[2][1] == 'X')
				//��ҵڶ������ڱ�Ե,���Ե�����������������䣬��ҵ��Ĳ���Ҫ�¡�б����
			{
				//��ҵ��Ĳ�û�ж¡�б����
				if (checkO(piece))
				{
					fill(piece);
				}
				//��ҵ��Ĳ����ˡ�б����
				else if (piece[1][0] == 'X' || piece[1][2] == 'X') //��ҵڶ������ڵڶ��еı�Ե
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
								cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //���Ե��岽���ڵ�����ͬһ�еĽ���
							}
				}
				else if (piece[0][1] == 'X' || piece[2][1] == 'X') //��ҵڶ������ڵڶ��еı�Ե
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
								cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //���Ե��岽���ڵ�����ͬһ�еĽ���
							}
				}
			}
			else if (piece[0][0] == 'X' || piece[0][2] == 'X' || piece[2][0] == 'X' || piece[2][2] == 'X')
				//��ҵڶ������ڽ��䣬���Ե�������������Խǣ���ʱ��������ֿ���
			{
				if (piece[0][1] == 'X') //��ҵ��Ĳ����ڵ�һ�еı�Ե
				{
					if (checkO(piece))
					{
						fill(piece);
					}
					else if (piece[0][0] == 'X' || piece[0][2] == 'X') //��ҵڶ������ڵ�һ��
					{
						for (int b = 0;b < 3;b++)
							if (piece[0][b] == ' ')
							{
								piece[0][b] = 'O';
								record[4][0] = 1;
								record[4][1] = b + 1;
								cout << "Computer: 1 " << b + 1 << "\n\n"; //���Ե��岽�¡�������
							}
					}
					else if (piece[2][0] == 'X' || piece[2][2] == 'X') //��ҵڶ������ڵ�����
					{
						for (int b = 0;b < 3;b = b + 2)
							if (piece[2][b] == 'X')
							{
								y = (b == 0) ? b + 2 : b - 2;
								piece[2][y] = 'O';
								record[4][0] = 3;
								record[4][1] = y + 1;
								cout << "Computer: 3 " << y + 1 << "\n\n"; //���Ե��岽������ҵڶ���ͬһ�еĽ���
							}
					}
				}
				else if (piece[1][0] == 'X' || piece[1][2] == 'X') //��ҵ��Ĳ����ڵڶ��еı�Ե
				{
					if (checkO(piece))
					{
						fill(piece);
					}
					else if (piece[0][0] == 'X' || piece[0][2] == 'X') //��ҵڶ������ڵ�һ��
					{
						for (int b = 0;b < 3;b = b + 2)
							if (piece[0][b] == 'X')
							{
								piece[2][b] = 'O';
								record[4][0] = 3;
								record[4][1] = b + 1;
								cout << "Computer: 3 " << b + 1 << "\n\n"; //���Ե��岽������ҵڶ���ͬһ�еĽ���
							}
					}
					else if (piece[2][0] == 'X' || piece[2][2] == 'X') //��ҵڶ������ڵ�����
					{
						for (int b = 0;b < 3;b = b + 2)
							if (piece[2][b] == 'X')
							{
								piece[0][b] = 'O';
								record[4][0] = 1;
								record[4][1] = b + 1;
								cout << "Computer: 1 " << b + 1 << "\n\n"; //���Ե��岽������ҵڶ���ͬһ�еĽ���
							}
					}
				}
				else if (piece[2][1] == 'X') //��ҵ��Ĳ����ڵ����еı�Ե
				{
					if (checkO(piece))
					{
						fill(piece);
					}
					else if (piece[0][0] == 'X' || piece[0][2] == 'X') //��ҵڶ������ڵ�һ��
					{
						for (int b = 0;b < 3;b = b + 2)
							if (piece[0][b] == 'X')
							{
								piece[2][b] = 'O';
								record[4][0] = 3;
								record[4][1] = b + 1;
								cout << "Computer: 3 " << b + 1 << "\n\n"; //���Ե��岽������ҵڶ���ͬһ�еĽ���
							}
					}
					else if (piece[2][0] == 'X' || piece[2][2] == 'X') //��ҵڶ������ڵ�����
					{
						for (int b = 0;b < 3;b = b + 2)
							if (piece[2][b] == ' ')
							{
								piece[2][b] = 'O';
								record[4][0] = 3;
								record[4][1] = b + 1;
								cout << "Computer: 3 " << b + 1 << "\n\n"; //���Ե��岽������ҵڶ���ͬһ�еĽ���
							}
					}
				}
				else //��ҵ��Ĳ����ڽ���
					blockUp(piece);
			}
		}
		else //���Ե�һ�����ڽ���
		{
			if (piece[1][1] == 'X')
				//��ҵڶ����������ģ���ʱ���Ե������ڵ�һ���ĶԽ�
			{
				if (checkO(piece))
				{
					fill(piece);
				}
				else if (piece[0][1] == 'X' || piece[1][0] == 'X' || piece[1][2] == 'X' || piece[2][1] == 'X') //��ҵ��Ĳ����ڱ�Ե
				{
					blockUp(piece); //���Ե��岽�¡�������
				}
				else if (piece[0][0] == 'X' || piece[0][2] == 'X' || piece[2][0] == 'X' || piece[2][2] == 'X') //��ҵ��Ĳ����ڽ���
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
								cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //���Ե��岽������ҵ��Ĳ��ĶԽ�
							}
				}
			}
			else
				//��ҵڶ������������ط�,��ʱ���Ե��������ڵ�һ��ͬ�л�ͬ�еĽ���
			{
				if (checkO(piece)) //��ҵ��Ĳ�û�ж¡���������������
				{
					fill(piece);
				}
				else //��ҵ��Ĳ��¡���������������
				{
					srand(static_cast<unsigned int>(time(0)));
					int i1 = rand() % 2;
					int j1 = rand() % 2;
					if (i1 == 1 && j1 == 1)
					{
						piece[1][1] = 'O';
						record[4][0] = 2;
						record[4][1] = 2;
						cout << "Computer: 2 2\n\n"; //���Ե��岽��������
					}
					else
					{
						if (record[0][0] == 1 && record[0][1] == 1) //���Ե�һ������1��1
						{
							piece[2][2] = 'O';
							record[4][0] = 3;
							record[4][1] = 3;
							cout << "Computer: 3 3\n\n";
						}
						else if (record[0][0] == 1 && record[0][1] == 3) //���Ե�һ������1��3
						{
							piece[2][0] = 'O';
							record[4][0] = 3;
							record[4][1] = 1;
							cout << "Computer: 3 1\n\n";
						}
						else if (record[0][0] == 3 && record[0][1] == 1) //���Ե�һ������3��1
						{
							piece[0][2] = 'O';
							record[4][0] = 1;
							record[4][1] = 3;
							cout << "Computer: 1 3\n\n";
						}
						else if (record[0][0] == 3 && record[0][1] == 3) //���Ե�һ������3��3
						{
							piece[0][0] = 'O';
							record[4][0] = 1;
							record[4][1] = 1;
							cout << "Computer: 1 1\n\n";
						}
					} //���Ե��岽���ڵ�һ���ĶԽ�
				}
			}
		}

		break;

	case 6://�������
		if (piece[1][1] == 'X') //��ҵ�һ����������
		{
			if (checkO(piece))
				fill(piece);
			else
				blockUp(piece);
		}
		else if (piece[1][1] == 'O') //��ҵ�һ��û��������
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
					cout << "Computer: 2 1\n\n"; //���Ե��������ڵڶ���
				}
				else if (piece[1][2] == ' ')
				{
					piece[1][2] = 'O';
					cout << "Computer: 2 3\n\n"; //���Ե��������ڵڶ���
				}
			}
		}
		break;

	case 7://��������
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
			cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //���Ե��߲���������
		}

		break;

	case 8://�������
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
			cout << "Computer: " << x + 1 << " " << y + 1 << "\n\n"; //���Եڰ˲���������
		}
		break;

	case 9://��������
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

