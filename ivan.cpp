#include <iostream>
#include <vector>
#include <list>
#include <random>

using namespace std;

int Choices();

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
			if (vct[3][j].value == 0)
			{
				vct[3][j].value = Choices();
				break;
			}else{}
		}
	
		break;
	
	case DOWN:

		for (int j = 0; j < 4; j++)
		{
			if (vct[0][j].value == 0)
			{
				vct[0][j].value = Choices();
				break;
			}else{}
		}

		break;
	case LEFT:

		for (int j = 0; j < 4; j++)
		{
			if (vct[j][3].value == 0)
			{
				vct[j][3].value = Choices();
				break;
			}else{}
		}
		break;

	case RIGHT:
		
		for (int j = 0; j < 4; j++)
		{
			if (vct[j][0].value == 0)
			{
				vct[j][0].value = Choices();
			}else{}
		}

		break;

	case CLEAR:
	//LEXA LOX))
		break;
	}
}

int Choices()
{
	exitCreateCell = true;
	std::vector<int> choices = { 4, 2 };
	std::random_device rd;
	std::mt19937 e{ rd() };
	std::uniform_int_distribution<std::size_t> dist{ 0, choices.size() - 1 };
	std::size_t i = dist(e);
	return choices[i];
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
	for (auto x : vct){
		for (auto c : x){
			cout << c.value << "\t";
		}
		cout << endl;
	}

	cout << endl << endl;

	btn = LEFT;
	CreateCell(vct);
	for (auto x : vct){
		for (auto c : x){
			cout << c.value << "\t";
		}
		cout << endl;
	}

	return 0;
}
