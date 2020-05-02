//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std; 

int main(){

    int board[10][10];

    for(int runner = 0; runner < 10;runner++){

        for(int secondRunner = 0; runner < 10; runner++){
            board[runner][secondRunner] = secondRunner;
        }
    }


    for(int runner = 0; runner < 10;runner++){

        for(int secondRunner = 0; runner < 10; runner++){
            cout << board[runner][secondRunner];
        }
    }





    return 0;
}