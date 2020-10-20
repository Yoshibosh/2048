#include <iostream>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
 
using namespace std;
 
int main()
{   
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

        cout << ch;

        if (ch == 27){
            check = true;
        }

        if (check){

            if (ch == 65){
                cout << "up\n";
            }
            if (ch == 66){
                cout << "down\n";
            }
            if (ch == 67){
                cout << "right\n";
            }
            if (ch == 68){
                cout << "left\n";
            }

        }

        cout << " AUE ";

    }
 
}