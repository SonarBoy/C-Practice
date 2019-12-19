#include <bits/stdc++.h>

using namespace std;

//FAILED ATTEMPTS:

//NOT REALIZING THAT YOU DO NOT NEED TO HARD STAMP THE VALUE

//NOT REALIZING THAT IT IS A REPEATED STRING SO THE THING THAT YOU 
//ARE TESTING AGAINST JUST HAS TO BE TESTED ONCE.

//REPEATING YOUR WORK JUST TO PROVE THAT IT CAN BE DONE THIS DOES NOT REALLY PROVE ANYTHING TO ANYONE 
//PEOPLE DONT CARE ABOUT THE PROCESS IF IT IS UNNECESSARILY REDUNDANT.

//NOT KEEPING YOUR EYES ON THE GOAL WHICH WAS TO FIND THE NUMBER OF REPEATS. MORE CONCERNED 
//WITH REBUILDING THE STRING TO HARD COUNT IT WHEN THERE WERE QUICKER WAYS TO DO IT. 

long repeatedString(string s, long leng) {

    long stringSize = s.length() ;
    long multiplier = 0;
    long numberOfAs = 0;
    

    for(int runner = 0; runner < stringSize; runner++){
        if(s[runner] == 'a'){
            numberOfAs++;
        }
    }

    bool multiplierNotFound = true;
    for(int runner;multiplierNotFound;runner++){
        if((stringSize * runner) >  leng){
            multiplier = stringSize * (runner - 1);
            numberOfAs = numberOfAs * (runner - 1);
            multiplierNotFound = false;
        }else if((stringSize * runner) ==  leng){
            multiplier = stringSize * runner;
            numberOfAs = numberOfAs * runner;
            multiplierNotFound = false;
        }
    }

    cout << "Test" <<numberOfAs; 
    
    return numberOfAs;
}



// Complete the repeatedString function below.
long repeatedString(string s, long leng) {

    long stringSize = s.length() ;
    long multiplier = 0;
    long numberOfAs = 0;
    

    for(int runner = 0; runner < stringSize; runner++){
        if(s[runner] == 'a'){
            numberOfAs++;
        }
    }

    long div = leng/s.length();
    long reminder = leng%s.length();

    numberOfAs = div*numberOfAs;


    //Inefficient------------------------------------
    /*
    bool multiplierNotFound = true;
    for(int runner;multiplierNotFound;runner++){
        if((stringSize * runner) >  leng){
            multiplier = stringSize * (runner - 1);
            numberOfAs = numberOfAs * (runner - 1);
            multiplierNotFound = false;
        }else if((stringSize * runner) ==  leng){
            multiplier = stringSize * runner;
            numberOfAs = numberOfAs * runner;
            multiplierNotFound = false;
        }
    }
    */
    //Inefficient------------------------------------

    for(int runner = 0; runner < reminder;runner++){
        if(s[runner] == 'a'){
            numberOfAs++;
        }
    }

    cout << "Test" <<numberOfAs; 

    
    return numberOfAs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
