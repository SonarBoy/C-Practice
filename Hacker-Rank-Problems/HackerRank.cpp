#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {

    
    string comp = "";
    int stepDesc = 0;
    int valleys = 0;

    for(int runner = 0; runner < n;runner++){

        comp = s[runner];

        if(comp.compare("U") == 0){
            stepDesc++; 

        if(stepDesc == 0){
            valleys++;
        }


        }else if(comp.compare("D") == 0){
            stepDesc--;

      

        }else{

        }

       
    }

    
    return valleys;

    //FAILED ATTEMPTS:
    //THINKING THAT YOU HAD TO COUNT THE MOUNTAINS
    // THINKING THAT KEY STROKES == ACTUAL SOUND WORK
    // NOT READING THE QUESTION CORRECTLY AND GETTING BOGGED DOWN BY AUX INFOMATION LIKE WHAT D AND U MEAN AND WHERE YOU SHOULD ALL ASSUME EVERY BODY SETS SEA LEVEL
    // NOT FOCUSING ON THE GOAL WHICH IN THIS CASE WAS COUNTING A VALLEY WHICH WAS DEMARCATED BY THE UPWARD MOTION OUT OF THE VALLEY GOING FROM -1 to 0


}

int jumpingOnClouds(vector<int> c) {

    
    int skip = 2;

    int jump = 0;

    for(int runner = 0; runner < c.size();runner++){

        if(skip > c.size()){
            jump++;
            break;
        }

        if(c[skip] == 0){
            jump++;
            runner = skip;
            skip += 2;
        }else{
            jump++;
            skip++;
        }

        
    }
    
    return jump;


    //FAILED ATTEMPTS:
    // THINKING THAT THERE WAS ANY RELATATION WITH THE NUMBER OF BAD CLOUNDS VS THE NUMBER OF GOOD CLOUDS MATHMETICALLY
    // THINKING THAT MODDIND THE NUMBER OF CLOUDS IN BETWEEN EACH OF THE THUNDER HEAD CLOUDS WOULD GET YOU CLOSER TO THE DESIRED RESULT 
    // NOT THINKING ABOUT THE DESIRED RESULT WHICH WAS JUST COUNT THE MINIMUM OF JUMPS AND THAT YOU COULD EASILY GET BY ACTUALLY DOING THE MINIMUN NUMBER OF JUMPS
    // ASSUMING THAT KEYSTROKES ARE ACCTUALLY GOING TO MAKE ANY DIFFERENCE WHEN YOUR LOGIC IS NOT SOUND
    // THE DISSONANCE BETWEEN 1 STEP AND 2 WHO IN THEIR RIGHT MIND WOULD TAKE 1 STEP WHEN YOU CAN TAKE TO THAT SHOULD HAVE BEEN YOUR GO TO LOGING FOOL!
}

#include <bits/stdc++.h>

using namespace std;

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

//FAILED ATTEMPTS:
//NOT REALIZING THAT YOU DO NOT NEED TO HARD STAMP THE VALUE;
//NOT REALIZING THAT IT IS A REPEATED STRING SO THE THING THAT YOU ARE TESTING AGAINST JUST HAS TO BE TESTED ONCE
//REPEATING YOUR WORK JUST TO PROVE THAT IT CAN BE DONE THIS DOES NOT REALLY PROVE ANYTHING TO ANYONE PEOPLE DONT CARE ABOUT THE PROCESS IF IT IS UNNECESSARILY REDUNDANT.
//NOT KEEPING YOUR EYES ON THE GOAL WHICH WAS TO FIND THE NUMBER OF REPEATS. MORE CONCERNED WITH REBUILDING THE STRING TO HARD COUNT IT WHEN THERE WERE QUICKER WAYS TO DO IT. 

int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {

    int spent = -1;

    
    for(int runner = 0;runner < keyboards.size()  ;runner++){
        for(int runner2 = 0; runner2 < drives.size() ;runner2++){

            if(drives[runner2] + keyboards[runner] <= b && drives[runner2] + keyboards                  [runner] > spent){
                spent = drives[runner2] + keyboards[runner];
                   
            }


        }

        
    }
    
    cout << "Money Spent: " << spent;
    return spent;

}

//FAILED ATTEMPTS:
//NOT KEEPING GOOD TRACK OF YOUR VARIABLE NAMES.
//NOT CORRECTLY WORKING WITH THE IDE AND FIGHTING IT UNNECESSARILY
//BLATANT DISREGARD FOR NAMING CONVENTION AND BEING OVERLY CONCERNED WITH EFFICIENCY.

// Complete the birthdayCakeCandles function below.
int birthdayCakeCandles(vector<int> ar) {

    int age = 0;
    int candles = 0;

    int runner2 = 1;
    for(int runner = 0;runner < ar.size() - 1;runner++){
        if(ar[runner2] > age){
            age = ar[runner2];
        }
        runner2++;
    }

    cout << "Greatest Age: " << age;
    for(int runner = 0; runner < ar.size();runner++){
        if(ar[runner] == age){
            candles++;
        }
    }

    return candles;
}

//FAILED ATTEMPTS:
//SAME BLATANT DISREGARD FOR THE ACTUAL END GOAL WHICH WOULD TAKE TWO LOOPS. WHEN I WAS TRYING TO SOLVE IT WITH NEEDLESS EFFIENCY
//NOT REALISING THE WHOLE IN MY LOGIC WHICH WAS A TEST FOR EACH ELEMENT IN THE ARRAY THROUGH THE LOOP AND NOT STICKING TO THE LARGEST ONE FOUND.

string kangaroo(int x1, int v1, int x2, int v2) {

    for(int runner = 0; runner < 10000;runner++){
        if(x1 == x2){
            return "YES";
        }

        x1 += v1;
        x2 += v2;
    }
    
    return "NO";
}

//FAILED ATTEMPTS:
//OVER THINKING THE PROBLEM AGAIN BECAUSE THERE WAS A POSSIBLE RELATATION TO THE INTERSECTIONS OF A LINE WHICH IS A SIMILAR TYPE OF QUESTION.


// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) {

    
    int months = 215;
    int feb = 28;

    int day = 0;

    if(year % 4 == 0){
        feb = 29;
    }

    day = 256 - (months + feb);

    string date = (day + ".09." + year);
    
    return date;


}




int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}