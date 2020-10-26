#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

string spaces(int);

void reverse(string &s)
{
    string newStr = "";
    for (int i = s.length() - 1;i >= 0;i--){
        newStr += s[i];
    }

    s = newStr;
}

string operator* (string s,int d){
    string result;

    while (d >= 0){
        result += s;
        d--; 
    }
    
    return result;

}

struct cell
{
    int x;
    int y;
    int value;
    cell();
};

cell::cell(){
    this->value = 0;
    this->x = 0;
    this->y = (int)(10 * rand()/RAND_MAX);
}


void print(vector<vector<cell>> vct)
{
    string gorizontal = "_";
    string vertical = "|" ;
    string space = " " ;

    int fieldSize = 5;
    int cellSide = 15;
    for (int i = 0;i < fieldSize * cellSide + 1;i++){ 


        if(i % cellSide == 0){
            for (int j = 0;j < fieldSize;j++){
                cout << vertical + gorizontal * (cellSide*2);
            }
        }else if(i == cellSide/2){
            for (int j = 0;j < fieldSize;j++){
                cout << vertical + space * (cellSide - 5 - 1 ) + spaces(vct[i][j].value) + (space * (cellSide - 1));
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



int main()
{

    srand(time(NULL));

    vector<vector<cell>> vct(10, vector<cell>(10));
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			vct[i][j].value = pow(2,j) *  log10(rand());
			vct[i][j].x = j;
			vct[i][j].y = i;
		}
	}

    print(vct);

    

    return 0;
}