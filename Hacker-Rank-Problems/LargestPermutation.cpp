#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestPermutation function below.
//! STILL BROKEN!
vector<int> largestPermutation(int numberOfSwaps, vector<int> inputArray) {
  vector<int> largestNumbers = inputArray;

  int computerlength = inputArray.size() - 1;
  int humanLength = inputArray.size();

  int counter = 0;
  int holder = 0;

  
  sort(largestNumbers.begin(), largestNumbers.end());

  // IF THE NUMBER OF SWAPS IS GREATER THAN THE ARRAY JUST SORT THE ARRAY AND
  // RETURN THE VALUE.
  if (numberOfSwaps > humanLength) {
    vector<int> out;

    for (int runner = computerlength; runner >= 0; runner--) {
      out.push_back(largestNumbers[runner]);
    }

    return out;
  }


  for (int outerRunner = 0; outerRunner <= numberOfSwaps - 1; outerRunner++) {

    for (int runner = 0; runner <= humanLength; runner++) {

      if (inputArray[runner] == largestNumbers[computerlength]) {

        cout << "Switching From <- with Value: " << inputArray[outerRunner]
             << " Position: " << outerRunner << endl;
        cout << "Switching To -> with Value: " << inputArray[runner]
             << " Position: " << runner << endl;

        // Testing A litte messed up but lets try it.

        holder = inputArray[outerRunner];
        inputArray[outerRunner] = inputArray[runner];
        inputArray[runner] = holder;

        cout << "Array Runner: " << runner << endl;
        cout << "Outer Runner: " << outerRunner << endl;


        cout << holder << endl;
        cout << inputArray[runner] << endl;
        cout << inputArray[outerRunner] << endl;
      }
    }

    computerlength--;
  }

  return inputArray;
}


//!BROKEN!
vector<int> largestPermutation(int k, vector<int> arr) {
    vector<int> largestNumbers = arr;
    vector<int> standardOutput = arr;
    
    int length = standardOutput.size() - 1;

    int length2 = standardOutput.size();
    
    int counter = 0;
    int holder = 0;



    //IF THE NUMBER OF SWAPS IS GREATER THAN THE ARRAY JUST SORT THE ARRAY AND RETURN THE VALUE.
    sort(largestNumbers.begin(),largestNumbers.end());

    

    
    for(int outerRunner = 0; outerRunner <= k - 1; outerRunner++){
        

        for(int runner = 0;runner < length2;runner++){


        if(standardOutput[runner] == largestNumbers[length]){
             cout << "Value: " << largestNumbers[length] << " in the sorted array." << endl;
             cout << "Unsorted Array Position: " << runner << " , Value: " << standardOutput[runner]<< endl;

             cout << endl;
            
             cout << "Switching To <- with Value: " << standardOutput[runner] << " Position: " << counter << endl; 
             cout << "Switching From -> with Value: " << standardOutput[counter] << " Position: " << runner << endl; 

            //Testing A litte messed up but lets try it.

            holder = arr[counter];
            arr[counter] = standardOutput[runner]; 
            arr[runner] = holder;
            

            
        }   

           


        }


        length--;
        counter++;
    }

    
    

    

    return arr;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = largestPermutation(k, arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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