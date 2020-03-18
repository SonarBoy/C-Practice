#include <string>


using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {

    

    //{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s''t','u','v','w','x','y','z'};

    vector<char> sentence;
    string tester = "";
    int trueK = k % 26;



    for(int runner = 0; runner < s.size();runner++){

        int charaterWithoutK = s[runner];
        int charaterWithK = 0;


        if((charaterWithoutK >= 65 && charaterWithoutK <= 90) || (charaterWithoutK >= 97 && charaterWithoutK <= 122)){

            charaterWithK = charaterWithoutK  + k;

            if((charaterWithK >= 90 && charaterWithoutK < 90) || (charaterWithK >= 122 && charaterWithoutK < 122)){
                charaterWithK = charaterWithK - 26;
                tester += char(charaterWithK);
            }else{
                tester += char(charaterWithK);
            }
            
        }else{
            tester += char(charaterWithoutK);
        }

    }


    return tester;
}