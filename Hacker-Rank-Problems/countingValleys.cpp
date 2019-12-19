#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
//FAILED ATTEMPTS:

//THINKING THAT YOU HAD TO COUNT THE MOUNTAINS
int countingValleys(int n, string s) {

    
    string comp = "";
    int stepDesc = 0;

    int valleys = 0;

    for(int runner = 1; runner < n;runner++){

        comp = s[runner];

        if(comp.compare("U") == 0){
            stepDesc++; 

            if(stepDesc == 1){
                valleys++;
            }

        }else if(comp.compare("D") == 0){
            stepDesc--;
        }else{}       
    }

    return valleys;
}



// THINKING THAT KEY STROKES == ACTUAL SOUND WORK
int countingValleys(int n, string s) {

    
    string comp = "";
    int stepDesc = 0;

    int valleys = 0;

    for(int runner = 1; runner < n;runner++){

        comp = s[runner];

        if(comp.compare("U") == 0){
            stepDesc++; 
            if(stepDesc == 1){
                valleys++;
            }

        }else if(comp.compare("D") == 0){
            stepDesc--;
        }else{}
    }

    return valleys;
}



// NOT READING THE QUESTION CORRECTLY AND GETTING BOGGED DOWN BY AUX INFOMATION LIKE WHAT 
// D AND U MEAN AND WHERE YOU SHOULD ALL ASSUME EVERY BODY SETS SEA LEVEL

// NOT FOCUSING ON THE GOAL WHICH IN THIS CASE WAS COUNTING A VALLEY WHICH WAS 
// DEMARCATED BY THE UPWARD MOTION OUT OF THE VALLEY GOING FROM -1 to 0

// Complete the countingValleys function below.
int countingValleys(int n, string s) {

    
    string comp = "";
    int stepDesc = 0;

    int valleys = 0;

    for(int runner = 1; runner <= n;runner++){

        comp = s[runner];

        if(comp.compare("U") == 0){
            stepDesc++; 

            if(stepDesc == 1){
                valleys++;
            }

        }else if(comp.compare("D") == 0){
            stepDesc--;
        }else{}
    }
    
    return valleys;
}


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
