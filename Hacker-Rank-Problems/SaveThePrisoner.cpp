#include <bits/stdc++.h>

using namespace std;

//! NOT TAKING INTO ACCOUNT THE FACT THAT IF THERE WERE LESS CANDIES THAN PRISONERS WHAT WOULD HAPPEN
int saveThePrisonerBAD1(int numberOfPrisoners, int sweets, int startChair) {

    int finalNumber = sweets % numberOfPrisoners;

    cout << "Final Number: "  << finalNumber << endl;

    startChair = startChair - 1;

    return (startChair + finalNumber);

}

//! ON THE RIGHT TRACK BUT NO CIGAR BECAUSE OUR LOGIC WAS STILL FLAWED THE NUMBER OF SWEETS CAN BE LESS BUT THAT
//! SHOULD NOT CHANGE THE MATH OF THE SITUATION
int saveThePrisonerBAD2(int numberOfPrisoners, int sweets, int startChair) {

    int finalNumber = 0;

    if(sweets < numberOfPrisoners){

        return (startChair + sweets) - 1;

    }else{
        
        finalNumber = sweets % numberOfPrisoners;
        //cout << "Final Number: "  << finalNumber << endl;

            startChair = startChair - 1;
        if((startChair + finalNumber) > numberOfPrisoners)
            finalNumber =  (startChair + finalNumber) % numberOfPrisoners;  
        else {
            finalNumber = (startChair + finalNumber);
        }


        return finalNumber;
    }

    return finalNumber;
}

//! FLAWED LOGIC AND NOT TAKING INTO CONSIDERATION THE RIGHT MATH.
int saveThePrisoner(int numberOfPrisoners, int sweets, int chairBegin) {

    if((sweets + chairBegin) > numberOfPrisoners)
    return ((sweets + chairBegin) % numberOfPrisoners) - 1; 


    if((sweets + chairBegin) < numberOfPrisoners)
    return (sweets + chairBegin) - 1;

    
   return 0;
  
}








vector<string> split_string(string);

// Complete the saveThePrisoner function below.
int saveThePrisoner(int numberOfPrisoners, int sweets, int startChair) {

 //* FIRST MOD THE NUMBER OF SWEETS BETWEEN THE PRISONERS TO GET HOW MANY SWEETS WOULD REMAIN
 //* NOTE THAT IF YOU HAD A SWEET NUMBER LESS THAN THE NUMBER OF PRISONERS YOU WOULDNT HAND ANYTHING OUT.
 int numberOfCandiesLeft  = sweets % numberOfPrisoners ;
 startChair -= 1;

   cout << "Number of candies left: " << numberOfCandiesLeft << endl;
   cout << "Number of candies + position of Prisoner: " << numberOfCandiesLeft + startChair << endl;

    //* NOW IF THE NUMBER OF CANDIES LEFT ADDED TO THE INDEX THAT YOU ARE STARTING TO HAND THEM OUT AT
    //* IS GREATER THAN THE NUMBER OF PRISONERS
   if(numberOfCandiesLeft + startChair > numberOfPrisoners){
       return (numberOfCandiesLeft + startChair) - numberOfPrisoners;
   }else{


       //* THIS IS THE CASE WHEN YOU HAVE ONE CANDY FOR EACH PRISONER AND ARE STARTING AT THE FIRST INDEX.
       if(numberOfCandiesLeft + startChair == 0){
           return numberOfPrisoners;
       }

       //* JUST RETURN THE NUMBER OF CANDIES LEFT + THE START CHAIR TO GET THE PRISONER YOU HAVE TO WARN.
       return numberOfCandiesLeft + startChair;
   }


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nms_temp;
        getline(cin, nms_temp);

        vector<string> nms = split_string(nms_temp);

        int n = stoi(nms[0]);

        int m = stoi(nms[1]);

        int s = stoi(nms[2]);

        int result = saveThePrisoner(n, m, s);

        fout << result << "\n";
    }

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
