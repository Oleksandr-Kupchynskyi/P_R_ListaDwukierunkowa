#ifndef NODE_H 
#define NODE_H

using namespace std;

class Node {
    
    private:
    int data;
    Node* prev;
    Node* next;

    public:
    Node(int wart) : data(wart), prev(nullptr), next(nullptr){}

    friend class ListaDwukierunkowa;
    friend class Iterator;
};

#endif