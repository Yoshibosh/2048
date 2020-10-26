#include <iostream>
#include <vector>
#include <list>
#include <random>

using namespace std;

bool exitCreateCell = false;

enum clickBtn {
	UP = 0,
	DOWN,
	LEFT,
	RIGHT,
	CLEAR
};

clickBtn btn = CLEAR;

struct cell
{
	short int x;
	short int y;
	short int value;
};

void CreateCell(vector<vector<cell>>& vct)
{
	switch (btn)
	{
	case UP:
		
		for (int j = 0; j < 4; j++)
		{
			if (exitCreateCell == false)
			{
				if (vct[3][j].y == 3)
				{
					cout << " == 3" << endl;

					if (vct[3][j].value == 0)
					{
						cout << "createCELL = true" << endl;
						exitCreateCell = true;
						std::vector<int> choices = { 4, 2 };
						std::random_device rd;
						std::mt19937 e{ rd() };
						std::uniform_int_distribution<std::size_t> dist{ 0, choices.size() - 1 };
						std::size_t i = dist(e);
						vct[3][j].value = choices[i];
					}
				}
			}
		}
		
		exitCreateCell = false;
	
		break;
	
	case DOWN:

		for (int j = 0; j < 4; j++)
		{
			if (exitCreateCell == false)
			{
				if (vct[0][j].y == 0)
				{
					cout << " == 3" << endl;

					if (vct[0][j].value == 0)
					{
						cout << "createCELL = true" << endl;
						exitCreateCell = true;
						std::vector<int> choices = { 4, 2 };
						std::random_device rd;
						std::mt19937 e{ rd() };
						std::uniform_int_distribution<std::size_t> dist{ 0, choices.size() - 1 };
						std::size_t i = dist(e);
						vct[0][j].value = choices[i];
					}
				}
			}
		}

		exitCreateCell = false;
		break;
	case LEFT:

		for (int j = 0; j < 4; j++)
		{
			if (exitCreateCell == false)
			{
				if (vct[j][3].x == 3)
				{
					cout << " == 3" << endl;

					if (vct[j][3].value == 0)
					{
						cout << "createCELL = true" << endl;
						exitCreateCell = true;
						std::vector<int> choices = { 4, 2 };
						std::random_device rd;
						std::mt19937 e{ rd() };
						std::uniform_int_distribution<std::size_t> dist{ 0, choices.size() - 1 };
						std::size_t i = dist(e);
						vct[j][3].value = choices[i];
					}
				}
			}
		}
		exitCreateCell = false;
		break;

	case RIGHT:
		
		for (int j = 0; j < 4; j++)
		{
			if (exitCreateCell == false)
			{
				if (vct[j][0].x == 0)
				{
					cout << " == 3" << endl;

					if (vct[j][0].value == 0)
					{
						cout << "createCELL = true" << endl;
						exitCreateCell = true;
						std::vector<int> choices = { 4, 2 };
						std::random_device rd;
						std::mt19937 e{ rd() };
						std::uniform_int_distribution<std::size_t> dist{ 0, choices.size() - 1 };
						std::size_t i = dist(e);
						vct[j][0].value = choices[i];
					}
				}
			}
		}
		exitCreateCell = false;
		break;

	case CLEAR:
		break;
	}
	
}

void sort(vector<vector<cell>>& vct)
{
	cell temp;
	cell tmp;
	for (int m = 0; m < 4; m++)
	{
		for (int n = 0; n < 4; n++)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (vct[m][n].y < vct[i][j].y)
					{
						tmp = vct[m][n];
						vct[m][n] = vct[i][j];
						vct[i][j] = tmp;
					}
				}
			}
		}
	}


	for (int m = 0; m < 4; m++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < (4 - 1); j++)
			{
				if (vct[m][j].x > vct[m][j + 1].x)
				{
					temp = vct[m][j];
					vct[m][j] = vct[m][j + 1];
					vct[m][j + 1] = temp;
				}
			}
		}
	}
	
}


int main()
{
	vector<vector<cell>> vct(4, vector<cell>(4));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			vct[i][j].value = 0;
			vct[i][j].x = j;
			vct[i][j].y = i;
		}
	}
	btn = UP;
	CreateCell(vct);
	btn = DOWN;
	CreateCell(vct);
	btn = LEFT;
	CreateCell(vct);
	btn = RIGHT;
	CreateCell(vct);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << vct[i][j].value << " ";
		}
		cout << endl;
	}
	cout << "------------------------------------------------------------------" << endl;
	vector<vector<cell>> vct_2(4, vector<cell>(4));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			vct[i][j].value = 0;
			vct[i][j].x = j;
			vct[i][j].y = i;
		}
	}
	btn = UP;
	CreateCell(vct);
	btn = DOWN;
	CreateCell(vct);
	btn = LEFT;
	CreateCell(vct);
	btn = RIGHT;
	CreateCell(vct);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << vct[i][j].value << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	cell aga = vct[0][0];
	vct[0][0] = vct[3][3];
	vct[3][3] = aga;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << vct[i][j].value << " ";
		}
		cout << endl;
	}

	sort(vct);
	cout << endl << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << vct[i][j].value << " ";
		}
		cout << endl;
	}

	return 0;
}
