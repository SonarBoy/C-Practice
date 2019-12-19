#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
//FAILED ATTEMPTS:

//NOT REALISING THE WHOLE IN MY LOGIC WHICH WAS A TEST FOR EACH ELEMENT IN 
THE ARRAY THROUGH THE LOOP AND NOT STICKING TO THE LARGEST ONE FOUND.

int birthdayCakeCandles(vector<int> ar) {

    int age = ar.size();
    int candles = 0;

    int runner2 = 0;
    for(int runner = 0;runner < ar.size();runner++){
        if((ar[runner] - 1) == age || ar[runner] == (age - 1)){
            candles++;
        }
        
    }

    return candles;
}


//SAME BLATANT DISREGARD FOR THE ACTUAL END GOAL WHICH WOULD TAKE TWO LOOPS. 
WHEN I WAS TRYING TO SOLVE IT WITH NEEDLESS EFFIENCY

int birthdayCakeCandles(vector<int> ar) {

    int age = ar.size();
    int candles = 0;

    int runner2 = 1;
    for(int runner = 0;runner2 < ar.size() - 1;runner++){
        if(ar[runner2] < ar[runner]){
            candles++;
        }
        runner2++;
    }

    return candles;
}
*/


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

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int ar_count;
    cin >> ar_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(ar_count);

    for (int i = 0; i < ar_count; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = birthdayCakeCandles(ar);

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
