#include <vector>
#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <cmath>
#include <string>
#include <ctime>
#include <random>
#include <thread>
#include <ctime>
#include <queue>
#include <mutex>

using namespace std;
	
bool isMove;

struct cell
{
	short int x;
	short int y;
	short int value;
	bool isAdd;
	bool isNew;
};

enum clickBtn
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT,
	CLEAR
};

string operator*(string s, int d)
{
	string result;

	while (d >= 0)
	{
		result += s;
		d--;
	}

	return result;
}

clickBtn getKey()
{
	clickBtn btn;
	int cache = 0;
	bool check = false;

	while (1)
	{

		struct termios oldt,
			newt;
		int ch;
		tcgetattr(STDIN_FILENO, &oldt);
		newt = oldt;
		newt.c_lflag &= ~(ICANON | ECHO);
		tcsetattr(STDIN_FILENO, TCSANOW, &newt);
		ch = getchar();
		tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

		if (ch == 27)
		{
			check = true;
		}

		if (check)
		{

			if (ch == 65)
			{
				return UP;
			}
			if (ch == 66)
			{
				return DOWN;
			}
			if (ch == 67)
			{
				return RIGHT;
			}
			if (ch == 68)
			{
				return LEFT;
			}
		}
	}
}

int Choices();

pair<int, int> CreateCell(vector<vector<cell>> &vct, clickBtn btn,bool isMove)
{

	int r = rand() % 4;
	int counter = 0;

	if (!isMove){
		return pair<int, int> {-1,-1}; 
	}

	switch (btn)
	{
	case UP:

		for (int j = r;counter < 4; j++)
		{
			if (j > 3){j = 0;}
			counter++;
			if (vct[3][j].value == 0)
			{
				vct[3][j].value = Choices();
				return pair<int, int>{vct[3][j].y, vct[3][j].x};
			}
			else
			{
			}
		}

		break;

	case DOWN:

		for (int j = r; counter < 4; j++)
		{
			if (j > 3){j = 0;}
			counter++;
			if (vct[0][j].value == 0)
			{
				vct[0][j].value = Choices();
				return pair<int, int>{vct[0][j].y, vct[0][j].x};
			}
			else
			{
			}
		}

		break;
	case LEFT:

		for (int j = r; counter < 4; j++)
		{
			if (j > 3){j = 0;}
			counter++;
			if (vct[j][3].value == 0)
			{
				vct[j][3].value = Choices();
				return pair<int, int>{vct[j][3].y, vct[j][3].x};
			}
			else
			{
			}
		}
		break;

	case RIGHT:

		for (int j = r; counter < 4; j++)
		{
			if (j > 3){j = 0;}
			counter++;
			if (vct[j][0].value == 0)
			{
				vct[j][0].value = Choices();
				return pair<int, int>{vct[j][0].y, vct[j][0].x};
			}
			else
			{
			}
		}

		break;

	case CLEAR:
		break;
	}
	return pair<int, int>{-1, 0};
}

int Choices()
{
	if (rand() % 9 > 7)
	{
		return 4;
	}
	else
	{
		return 2;
	}
}

void sort(vector<vector<cell>> &vec)
{
	bool check = true;
	cell temp;
	while (check)
	{

		check = false;

		for (int i = 0; i < vec.size(); i++)
		{
			for (int j = 0; j < vec.size(); j++)
			{
				// cout << "\nreal = " << j << "  X=" << vec[i][j].x << "\treal = " << i << "  Y=" << vec[i][j].y << endl;
				if (vec[i][j].y != i | vec[i][j].x != j)
				{
					check = true;

					// cout << "\nAAAUEY ====== " << vec[2][2].value << endl;
					// cout << "\nreal = " << j << "  X=" << vec[i][j].x << "\treal = " << i << "  Y=" << vec[i][j].y << endl;

					temp = vec[vec[i][j].y][vec[i][j].x];
					vec[vec[i][j].y][vec[i][j].x] = vec[i][j];

					if (temp.value == 0)
					{
						temp.y = i;
						temp.x = j;
					}
					vec[i][j] = temp;
				}
			}
		}
	}
}

string spaces(int);

void reverse(string &s)
{
	string newStr = "";
	for (int i = s.length() - 1; i >= 0; i--)
	{
		newStr += s[i];
	}
	s = newStr;
}

string backColor(int val)
{
	if (val == 2)
	{
		return "253";
	}
	else if (val == 4)
	{
		return "229";
	}
	else if (val == 8)
	{
		return "222";
	}
	else if (val == 16)
	{
		return "215";
	}
	else if (val == 32)
	{
		return "202";
	}
	else if (val == 64)
	{
		return "52";
	}
	else if (val > 64 && val < 4096)
	{
		return "226";
	}
	else if (val > 4096)
	{
		return "28";
	}
	return "8";
}

void print(vector<vector<cell>> &vec, int fieldSize = 5, int cellSize = 5)
{
	string gorizontal = "_";
	string vertical = "|";
	string space = " ";
	string slash = "/";
	string beginE1 = "\x1b[48;5;";
	string beginE2 = "m";
	string endE = "\x1b[0m";

	for (int i = 0; i < vec.size(); i++)
	{

		for (int j = 0; j < fieldSize; j++)
		{
			cout << beginE1 + "8" + beginE2 + space * (cellSize * 2 + 1) + endE;
		}
		cout << endl;

		for (int k = 0; k < cellSize + 1; k++)
		{

			for (int j = 0; j < vec.size(); j++)
			{

				if (vec[i][j].value == 0)
				{
					cout << beginE1 + "8" + beginE2 + space + endE << beginE1 + backColor(vec[i][j].value) + beginE2 + space * (cellSize * 2) + endE;
				}
				else if (vec[i][j].value != 0)
				{
					if (vec[i][j].isNew)
					{
						if (k == cellSize / 2)
						{
							cout << beginE1 + "8" + beginE2 + space + endE << beginE1 + "8" + beginE2 + space * (cellSize - 6) + spaces(vec[i][j].value) + space * (cellSize - 1) + endE;
						}
						else
						{
							cout << beginE1 + "8" + beginE2 + space + endE << beginE1 + "8" + beginE2 + space * (cellSize * 2) + endE;
						}
					}
					else if (vec[i][j].isAdd)
					{
						if (k == cellSize / 2)
						{
							cout << beginE1 + "157" + beginE2 + space + endE << beginE1 + "157" + beginE2 + space * (cellSize - 6) + spaces(vec[i][j].value) + space * (cellSize - 1) + endE;
						}
						else
						{
							cout << beginE1 + "157" + beginE2 + space + endE << beginE1 + "157" + beginE2 + space * (cellSize * 2) + endE;
						}
					}
					else
					{

						if (k == cellSize / 2)
						{
							cout << beginE1 + "8" + beginE2 + space + endE << beginE1 + backColor(vec[i][j].value) + beginE2 + space * (cellSize - 6) + spaces(vec[i][j].value) + space * (cellSize - 1) + endE;
						}
						else
						{
							cout << beginE1 + "8" + beginE2 + space + endE << beginE1 + backColor(vec[i][j].value) + beginE2 + space * (cellSize * 2) + endE;
						}
					}
				}
				else
				{
					cout << beginE1 + "8" + beginE2 + space + endE << beginE1 + backColor(vec[i][j].value) + beginE2 + slash * (cellSize * 2) + endE;
				}
			}

			cout << endl;
		}
	}
}

string spaces(int d)
{
	string space = " ";
	string s;
	int counter = 0, cache = d, index;

	char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	while (d > 0)
	{
		d /= 10;
		counter++;
	}

	for (int i = 0; i < counter; i++)
	{
		index = (cache / (int)pow(10, i)) % 10;
		s += digits[index];
	}

	reverse(s);

	return s = space * (5 - counter) + s;
}

bool WhatCellInPath(vector<cell>, vector<cell>)
{
	return 0;
}

pair<int, int> find(vector<vector<cell>> &vec, short int x, short int y)
{
	for (int a = 0; a < vec.size(); a++)
	{
		for (int b = 0; b < vec.size(); b++)
		{
			if (vec[a][b].x == x)
			{
				if (vec[a][b].y == y)
				{
					return pair<int, int>(a, b);
				}
			}
		}
	}
	cout << "ты ебанутый чтоли?" << endl;
	return pair<int, int>(-1, -1);
}

bool move(vector<vector<cell>> &vec, clickBtn btn)
{
	pair<int, int> ab;
	cell temp;
	int x, y;
	bool result = false;
	switch (btn)
	{
	case UP:
		for (int j = 0; j < vec.size(); j++)
		{

			for (int i = 0; i < vec.size(); i++)
			{

				//cout << i << "\t" << j << endl;

				if (vec[i][j].value != 0)
				{

					temp = vec[i][j];

					while (1)
					{

						ab = find(vec, temp.x, temp.y - 1);

						if (ab.first == -1)
						{
							break;
						}

						if (vec[ab.first][ab.second].value == 0)
						{

							result = true;			

							vec[temp.y][temp.x] = vec[ab.first][ab.second];

							vec[temp.y][temp.x].y = temp.y;
							vec[temp.y][temp.x].x = temp.x;

							temp.y = ab.first;
							temp.x = ab.second;

							vec[ab.first][ab.second] = temp;

							// cout << "X=\t" << temp.x << "Y=\t" << temp.y << endl;
						}
						else if (vec[ab.first][ab.second].value == vec[temp.y][temp.x].value && !vec[ab.first][ab.second].isAdd)
						{

							vec[ab.first][ab.second].isAdd = true;

							vec[ab.first][ab.second].value *= 2;
							vec[temp.y][temp.x].value = 0;

							// cout << "EPJOQW" << endl;
							result = true;

							break;
						}
						else if (vec[ab.first][ab.second].value != 0)
						{
							//cout << vec[ab.first][ab.second].value << "AAAWEQ" << endl;
							break;
						}
						//cout << "Jija\t" << i << "\t" << j << endl;
					}
				}
			}
		}
		break;
	case DOWN:
		for (int j = 0; j < vec.size(); j++)
		{

			for (int i = vec.size() - 1; i >= 0; i--)
			{

				//cout << i << "\t" << j << endl;

				if (vec[i][j].value != 0)
				{

					temp = vec[i][j];

					while (1)
					{

						ab = find(vec, temp.x, temp.y + 1);

						if (ab.first == -1)
						{
							break;
						}

						if (vec[ab.first][ab.second].value == 0)
						{

							vec[temp.y][temp.x] = vec[ab.first][ab.second];

							vec[temp.y][temp.x].y = temp.y;
							vec[temp.y][temp.x].x = temp.x;

							temp.y = ab.first;
							temp.x = ab.second;

							result = true;

							vec[ab.first][ab.second] = temp;

							// cout << "X=\t" << temp.x << "Y=\t" << temp.y << endl;
						}
						else if (vec[ab.first][ab.second].value == vec[temp.y][temp.x].value && !vec[ab.first][ab.second].isAdd)
						{

							vec[ab.first][ab.second].isAdd = true;

							vec[ab.first][ab.second].value *= 2;
							vec[temp.y][temp.x].value = 0;

							result = true;

							break;
						}
						else if (vec[ab.first][ab.second].value != 0)
						{
							//cout << vec[ab.first][ab.second].value << "AAAWEQ" << endl;
							break;
						}
						//cout << "Jija\t" << i << "\t" << j << endl;
					}
				}
			}
		}
		break;
	case LEFT:
		for (int i = 0; i < vec.size(); i++)
		{

			for (int j = 0; j < vec.size(); j++)
			{

				//cout << i << "\t" << j << endl;

				if (vec[i][j].value != 0)
				{

					temp = vec[i][j];

					while (1)
					{

						ab = find(vec, temp.x - 1, temp.y);
						// cout << " KPOQEJKPOFJPOEQWJ\t"
							//  << "1 - " << ab.first << "2 - " << ab.second << endl;

						if (ab.first == -1)
						{
							break;
						}

						if (vec[ab.first][ab.second].value == 0)
						{

							vec[temp.y][temp.x] = vec[ab.first][ab.second];

							result = true;

							vec[temp.y][temp.x].y = temp.y;
							vec[temp.y][temp.x].x = temp.x;

							temp.y = ab.first;
							temp.x = ab.second;

							vec[ab.first][ab.second] = temp;

							// cout << "X=\t" << temp.x << "Y=\t" << temp.y << endl;
						}
						else if (vec[ab.first][ab.second].value == vec[temp.y][temp.x].value && !vec[ab.first][ab.second].isAdd)
						{

							vec[ab.first][ab.second].isAdd = true;
							vec[ab.first][ab.second].value *= 2;
							vec[temp.y][temp.x].value = 0;

							result = true;

							break;
						}
						else if (vec[ab.first][ab.second].value != 0)
						{
							//cout << vec[ab.first][ab.second].value << "AAAWEQ" << endl;
							break;
						}
						//cout << "Jija\t" << i << "\t" << j << endl;
					}
				}
			}
		}
		break;
	case RIGHT:
		for (int i = 0; i < vec.size(); i++)
		{

			for (int j = vec.size(); j >= 0; j--)
			{

				//cout << i << "\t" << j << endl;

				if (vec[i][j].value != 0)
				{

					temp = vec[i][j];

					while (1)
					{

						ab = find(vec, temp.x + 1, temp.y);

						if (ab.first == -1)
						{
							break;
						}

						if (vec[ab.first][ab.second].value == 0)
						{

							vec[temp.y][temp.x] = vec[ab.first][ab.second];

							vec[temp.y][temp.x].y = temp.y;
							vec[temp.y][temp.x].x = temp.x;

							temp.y = ab.first;
							temp.x = ab.second;

							vec[ab.first][ab.second] = temp;

							result = true;

							// cout << "X=\t" << temp.x << "Y=\t" << temp.y << endl;
						}
						else if (vec[ab.first][ab.second].value == vec[temp.y][temp.x].value && !vec[ab.first][ab.second].isAdd)
						{

							vec[ab.first][ab.second].isAdd = true;
							vec[ab.first][ab.second].value *= 2;
							vec[temp.y][temp.x].value = 0;
							
							result = true;

							break;
						}
						else if (vec[ab.first][ab.second].value != 0)
						{
							//cout << vec[ab.first][ab.second].value << "AAAWEQ" << endl;
							break;
						}
						//cout << "Jija\t" << i << "\t" << j << endl;
					}
				}
			}
		}
		break;

	default:
		break;
	}
	return result;
}

void animation(vector<vector<cell>> &vec, pair <int,int> xy)
{
	mutex mut;
	if (xy.first != -1)
		{
			for (int k = 0; k < 6; k++)
			{
				if (k % 2 == 0)
				{
					vec[xy.first][xy.second].isNew = true;
				}
				else
				{
					vec[xy.first][xy.second].isNew = false;
				
				}
				
	

				print(vec, 4, 10);
				
				this_thread::sleep_for(100ms);
			}
		}

	for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				vec[i][j].isAdd = false;
			}
		}

		this_thread::sleep_for(100ms);
		print(vec, 4, 10);
}


int main()
{
	vector<vector<cell>> vec(4, vector<cell>(4));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			vec[i][j].value;
			vec[i][j].x = j;
			vec[i][j].y = i;
			vec[i][j].isAdd = false;
			vec[i][j].isNew = false;
		}
	}

	thread t1;

	clickBtn btn;
	//qw
	srand(rand() % 200);

	vec[rand() % 3][rand() % 3].value = 2;

	pair<int, int> xy;
	bool isMove;
	bool gameover = false;

	btn = getKey();

	while (1)
	{
		btn = getKey();


		print(vec, 4, 10);

	
		this_thread::sleep_for(100ms);
		isMove = move(vec, btn);
		xy = CreateCell(vec, btn,isMove);

		// t1 = thread{animation,&vec,xy};

		if (!isMove){
			gameover = true;
		}

		// animation(vec,xy);
		for (auto &i : vec){
			for (auto &j : i){
				if (!isMove){
					if (j.value == 0){
						gameover = false;
						break;
					}
				}
			}
		}

		if (gameover){
			cout << "\nВы проиграли... :(" << endl;
			return 0;
		}

		animation(vec,xy);
		cout << endl;

	}
}