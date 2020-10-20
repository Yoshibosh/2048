#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

bool GAMEOVER = false;


//Умножает строку на целое число #пример - "+" * 5 = "+++++";
string operator * (string s,size_t d){
    string result;

    while (d >= 0){
        result += s;
        d--; 
    }
    
    return result;

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


int main()
{

     

    string soloxa = "=||=";

    cout <<  soloxa * 10;

    return 0;
}




