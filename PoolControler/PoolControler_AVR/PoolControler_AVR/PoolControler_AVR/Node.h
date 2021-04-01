
#include <string.h>

class Node {
    std::string val;
    Node* next;
public:
    Node(std::string val, Node* nxt);
    std::string getVal();
    Node* getNext();
    void setNext(Node* nxt);
};