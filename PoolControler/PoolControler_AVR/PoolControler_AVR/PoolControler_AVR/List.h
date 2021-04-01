
#include "Node.cpp"

class List {
    Node* head;
public:
    List();
    ~List();
    void insertAfterLast(char* dat);
    char* removeFirst();
    char* removeNode(char* dat);
};