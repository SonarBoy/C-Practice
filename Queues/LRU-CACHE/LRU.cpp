#include <list>
#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache{

    //Stores Keys of cache.
    list<int> dq;

    //Store references of keys in cache.
    unordered_map<int, list<int>::iterator> ma;

    //maximum capacity of cache.
    int csize;

    public:
        LRUCache(int);
        void refer(int);
        void display();
};


//Constructor for size;
LRUCache::LRUCache(int n){
    csize = n;
}

void LRUCache::refer(int x){

    //value not present in cache
    if(ma.find(x) == ma.end()){
        
        // cache is full
        if(dq.size() == csize){

            //get the element index at the last position.
            int last = dq.back();   

            //Delete last element 
            //* http://www.cplusplus.com/reference/vector/vector/pop_back/
            dq.pop_back();

            //Deletes element from map
            //* http://www.cplusplus.com/reference/unordered_map/unordered_map/erase/
            ma.erase(last);

        }
    }else{
        dq.erase(ma[x]);
    }

        //Update the value in the reference.
        dq.push_front(x);
        ma[x] = dq.begin();
    
}

void LRUCache::display(){
    for(auto it = dq.begin(); it != dq.end(); it++){
        cout << (*it) << " ";
    }

    cout << endl;
}

int main() 
{ 
    LRUCache ca(4); 
  
    ca.refer(1); 
    ca.refer(2); 
    ca.refer(3); 
    ca.refer(1); 
    ca.refer(4); 
    ca.refer(5); 
    ca.display(); 
  
    return 0; 
} 