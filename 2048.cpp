#include <vector>
#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <cmath>
#include <string>
#include <ctime>
#include <random>

 
using namespace std;


struct cell
{
	short int x;
	short int y;
	short int value;
};



enum clickBtn {
	UP = 0,
	DOWN,
	LEFT,
	RIGHT,
	CLEAR
};

string operator* (string s,int d){
    string result;

    while (d >= 0){
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

    while(1){
 
        struct termios oldt,
        newt;
        int ch;
        tcgetattr( STDIN_FILENO, &oldt );
        newt = oldt;
        newt.c_lflag &= ~( ICANON | ECHO );
        tcsetattr( STDIN_FILENO, TCSANOW, &newt );
        ch = getchar();
        tcsetattr( STDIN_FILENO, TCSANOW, &oldt );


		if (ch == 27){
			check = true;
		}

        if (check){

            if (ch == 65){
                return UP;
            }
            if (ch == 66){
                return DOWN;
            }
            if (ch == 67){
                return RIGHT;
            }
            if (ch == 68){
                return LEFT;
            }

        }
    }
}

int Choices();


void CreateCell(vector<vector<cell>> &vct,clickBtn btn)
{

	int r = rand() % 4;

	switch (btn)
	{
	case UP:
		
		for (int j = r; j < 4; j++)
		{
			if (vct[3][j].value == 0)
			{
				vct[3][j].value = Choices();
				break;
			}else{}
		}
	
		break;
	
	case DOWN:

		for (int j = r; j < 4; j++)
		{
			if (vct[0][j].value == 0)
			{
				vct[0][j].value = Choices();
				break;
			}else{}
		}

		break;
	case LEFT:

		for (int j = r; j < 4; j++)
		{
			if (vct[j][3].value == 0)
			{
				vct[j][3].value = Choices();
				break;
			}else{}
		}
		break;

	case RIGHT:
		
		for (int j = r; j < 4; j++)
		{
			if (vct[j][0].value == 0)
			{
				vct[j][0].value = Choices();
				break;
			}else{}
		}

		break;

	case CLEAR:
		break;
	}
}

int Choices()
{
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


string spaces(int);

void reverse(string &s)
{
    string newStr = "";
    for (int i = s.length() - 1;i >= 0;i--){
        newStr += s[i];
    }
    s = newStr;
}

void print(vector<vector<cell>>& vct,int fieldSize = 5,int cellSide = 5)
{
    string gorizontal = "_";
    string vertical = "|" ;
    string space = " " ;

    
    for (int i = 0;i < fieldSize * cellSide + 1;i++){ 


        if(i % cellSide == 0){
            for (int j = 0;j < fieldSize;j++){
                cout << vertical + gorizontal * (cellSide*2);
            }
        }else if(i % cellSide/2 == 0){
            for (int j = 0;j < fieldSize;j++){
                cout << vertical + space * (cellSide - 5 - 1 ) + spaces(vct[i/cellSide][j].value) + (space * (cellSide - 1));
            }
        }else{
            for (int j = 0;j < fieldSize;j++){
                cout << vertical + space * (cellSide*2);
            }
        }

        cout << vertical << endl;
    }
}

string spaces(int d)
{
    string space = " " ;
    string s;
    int counter = 0,cache = d,index;

    char digits[10] = {'0','1','2','3','4','5','6','7','8','9'};

    while(d > 0){
        d /= 10;
        counter++;
    }

    for (int i = 0;i < counter;i++){
        index = (cache / (int)pow(10,i)) % 10;
        s += digits[index]; 
    }
    
    reverse(s);
    
    return s = space * (5 - counter) + s;
}

bool WhatCellInPath(vector<cell>,vector<cell>)
{

}


void move(vector<vector<cell>> &vec,clickBtn btn)
{
	switch (btn)
	{
	case UP:
		for (int j = 1;j < vec.size();j++){
				
				vec[j][j]
			
			for (int i = 1;i < vec.size();i++){
				
			}

		}
		break;
	case DOWN:
		break;
	case LEFT:
		break;
	case RIGHT:
		break;
	
	default:
		break;
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

	
	clickBtn btn;
	
	
	while (1){
		btn = getKey();
		CreateCell(vct,btn);
		for (auto x : vct){
			for (auto c : x){
				cout << c.value << "\t";
			}
			cout << endl;
			print(vct,4,10);
		}
	}


}