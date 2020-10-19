#include <iostream>
#include <string>

using namespace std;

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

cell *operator+(cell *second)
    {
        this->Ivan = this->Ivan + second->Ivan;

        delete second;
        return;
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



    cell(int value,int x,int y);
    ~cell();
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


int main(){

    okno(25,25);

    cell *c1 = new cell (2,1,1);
    cell *c2 = new cell (8,1,2);
    cell *c3 = new cell (16,1,3);

    // cell c1(2,1,1),c2(8,1,2),c3(16,1,3); 

    c1 + c2;

    c3->out();
    c1->out();
    c2->out();

    cout << "Anal"; 

    return 0;
}




