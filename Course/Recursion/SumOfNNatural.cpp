#include <iostream>
#include <string>
#include <chrono>

using namespace std;


int natural(int num){

    if(num <= 0){
        return 0;
    }else{
        return natural(num - 1) + num;
    }
}

int naturalCounter(int num, int counter){

    if(counter == num){
        return counter;
    }else{
        return naturalCounter(num,counter + 1) + counter;
    }

}

int sum(int num){
    return (num * (num + 1))/2;
}

int fibo(int num){

    if(num == 0){
        cout << 0 << endl;
        return 0;
    }else if(num == 1){

        cout << 0 << endl;
        return 1;
    }else{
        cout << "(" <<(num - 1) << " + " << (num - 2) << ")" << endl;
        return fibo(num - 1) + fibo(num - 2);
    }

}

int main(){ 
    int number = 0;

    clock_t start;
    long double duration;

    start = clock();
    number = natural(1000);
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

    cout << "Number: " << number << " Duration: "<< duration << endl;
    



    int counter = 0;

    
    duration = 0;   

    start = clock();
    counter = naturalCounter(1000,0);
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

    cout << "Number: " << counter << " Duration: "<< duration << endl;   


    int fiboNumber = 0;

    fiboNumber = fibo(8);

    cout << "Fibo Number: " << fiboNumber << endl;

    return 0;   
}