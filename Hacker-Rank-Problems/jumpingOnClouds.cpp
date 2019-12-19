#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

//FAILED ATTEMPTS:

//THINKING THAT THERE WAS ANY RELATATION WITH THE NUMBER OF 
//BAD CLOUNDS VS THE NUMBER OF GOOD CLOUDS MATHMETICALLY
int jumpingOnClouds(vector<int> c) {

    int badClouds = 0;
    int jumps = 0;
    
    for(int runner = 0; runner < c.size(); runner++){
        if(c[runner] == 1){
            badClouds++;
        }   
    }

    if(badClouds % 2 == 0){
        jumps = ((c.size() - badClouds)/2);
    }
    
    if(badClouds % 2 != 0){
        jumps = ((c.size() - badClouds)/2) + (badClouds % 2);
    }
    

    return jumps;
}

//THINKING THAT MODDIND THE NUMBER OF CLOUDS IN BETWEEN EACH OF THE THUNDER HEAD CLOUDS 
//WOULD GET YOU CLOSER TO THE DESIRED RESULT 
int jumpingOnClouds(vector<int> c) {

    int goodClouds = 0;
    
    int jumps = 0;
    


    for(int runner = 0; runner < c.size(); runner++){
        if(c[runner] == 0){
            goodClouds++;
        }

       
    }

    int badClouds = c.size() - goodClouds;

    return goodClouds;
}

//NOT THINKING ABOUT THE DESIRED RESULT WHICH WAS JUST COUNT THE MINIMUM OF JUMPS AND THAT 
//YOU COULD EASILY GET BY ACTUALLY DOING THE MINIMUN NUMBER OF JUMPS
int jumpingOnClouds(vector<int> c) {

    int badClouds = 0;
    int jumps = 0;
    


    for(int runner = 0; runner < c.size(); runner++){
        if(c[runner] == 1){
            badClouds++;
        }
    }

    if(badClouds % 2 == 0){
        jumps = ((c.size() - badClouds)/2);
    }
    
    if(badClouds % 2 != 0){
        jumps = ((c.size() - badClouds)/2) + (badClouds % 2);
    }
    
    return jumps;
}



//ASSUMING THAT KEYSTROKES ARE ACCTUALLY GOING TO MAKE ANY DIFFERENCE WHEN YOUR LOGIC IS NOT SOUND
//THE DISSONANCE BETWEEN 1 STEP AND 2 WHO IN THEIR RIGHT MIND WOULD TAKE 
int jumpingOnClouds(vector<int> c) {

    int goodClouds = 0;
    
    int jumps = 0;
    


    for(int runner = 0; runner < c.size(); runner++){
        if(c[runner] == 0){
            goodClouds++;
        }

       
    }

    int badClouds = c.size() - goodClouds;

    if(badClouds % 2 == 0){
        jumps = goodClouds - 1;
    }

    if(badClouds % 2 != 0){
        jumps = goodClouds + (badClouds % 2);
    }

    return jumps;


}

//1 STEP WHEN YOU CAN TAKE TO THAT SHOULD HAVE BEEN YOUR GO TO LOGING FOOL!
int jumpingOnClouds(vector<int> c) {
    
    int hop = 1;
    int skip = 2;

    int jump = 0;
    

    for(int runner = 0; runner < c.size(); runner++){

        if(skip > c.size()){
            break;
        }

        if(c[skip] == 0){
            jump++;
            runner = skip;
            skip += 2;
        }


        if(c[hop] == 0){
            jump++;
            hop++; 
        }

        hop++;
        skip++;
        
    }

    return jump;
}


// Complete the jumpingOnClouds function below.
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
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
