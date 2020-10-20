#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

bool GAMEOVER = false;

string operator * (string s,int d){
    string result;

    while (d >= 0){
        result += s;
        d--; 
    }
    
    return result;

}

class cell
{
private:
    int x,y;
    int Ivan;
    string soloxa;
public:

cell(int value,int x,int y);
~cell();

cell *operator+(cell *second)
    {
        this->Ivan = this->Ivan + second->Ivan;

        delete second;
        return second;
    }


    void out(){
        cout << "value = " << this->getIvan() << endl;
    }


    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    int getIvan()
    {
        return Ivan;
    }
    string getSoloxa()
    {
        return soloxa;
    }

    void setIvan(int Ivan)
    {
        this->Ivan = Ivan;
    }


};

cell::cell(int value,int x,int y)
{
    Ivan = value;
    this->soloxa = soloxa;
    this->x = x;
    this->y = y;
}

cell::~cell()
{
    
}

int okno(size_t width, size_t hieght){

    string s = "#",space = " ";

    cout << s * width << endl;

    for (size_t t=0;t <= hieght/2;t++){
        cout << "|" << space * (width - 2) << "|" << endl;
    }

    cout << s * width << endl;

    return 0;
}

// cell* operator+(cell &first,cell *second)
//     {
//         first.setIvan(first.getIvan() + second->getIvan());
//         delete second;
//     }




int main()
{

    while (!GAMEOVER){
        break;
    }   

    

    okno(25,25);

    cout << "Anal"; 

    return 0;
}




