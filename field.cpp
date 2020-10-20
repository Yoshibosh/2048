#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
#include <queue>

using namespace std;

class field
{
private:

    struct cell
    {
        short int x;
        short int y;
        short int value;
        cell();
    };

public:
    cell* CreateNewCell();

    list<cell> Node;
 
    field();
    ~field();

};

field::cell::cell()
{
    x = 0;
    y = 0;
    value = 2;
}

field::field()
{
}

field::~field()
{
}

field::cell* field::CreateNewCell()
{ 
    cell *cl = new cell();
    return cl;
}

// int okno(const field &fld)
// {
//     {2,0,0,8,8,0,16,0,0,0,0,0,0,0,0}
//     __________
//     |   |   |   |
//     |   |   |   |
//     2   0   0   8
//     |
//     |
//     |
//     |
//     8   0   16  0
//     |
//     |
//     |
//     |
//     0   0   0   0
//     |
//     |
//     |
//     |
//     0   0   0   0
// }





int main()
{

}