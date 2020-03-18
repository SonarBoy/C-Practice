#include <iostream>
using namespace std;

class Node{
    public:
    struct Node* next;
    int data;
    Node(int data) 
    { 
        this->data = data; 
        next = NULL; 
    };
};