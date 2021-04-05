#include "Node.h"
#include "Headers.h"

class List {
    Node* head;
public:
    List();
    ~List();
    void insertAfterLast(char* dat);
    char* removeFirst();
    char* removeNode(char* dat);
    void listAll();
};