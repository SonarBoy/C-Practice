#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    cout << "Create a pointer (int * pntr)" << endl;

    int x[10] = {1,2,3,4,5,6,7,8,9,10};


    int * pntr;

    pntr = &x[0];

    for(int indx = 0; indx < 10; indx++){
        cout << "Address of X array index " << indx << " :" << &x[indx] <<endl;
    }

    cout << endl;
    cout << "Here we now get the second address from the Array we created earlier via the '&' operator and just adding 1 to it "<< endl;
    cout << (&x[0] + 1) << endl;
    cout << *(&x[0] + 1) << endl;


    
    std::ostringstream strm;
    strm << (&x[0] + 1);
    string str = strm.str();

    unsigned int pntrIntAdd;
    sscanf(str.c_str(), "%x", &pntrIntAdd);

    str.clear();
    strm.str(std::string());
    
    
    cout << "Now here is the address in an int form: " << pntrIntAdd  << endl;
    cout << endl;
    cout << endl;


    for(int indx = 0; indx < 10; indx++){
        cout << "REAL ADDRESS: " << (&x[indx]);
        strm << (&x[indx]);
        str = strm.str();

        unsigned int pntrIntAdd;
        sscanf(str.c_str(), "%x", &pntrIntAdd);

        cout << " INT Address of X array index " << indx << " :" << pntrIntAdd <<endl;
        str.clear();
        strm.str(std::string());
    }





}