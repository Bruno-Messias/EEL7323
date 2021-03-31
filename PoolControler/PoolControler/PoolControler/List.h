
#include "Node.cpp"

class List {

    Node* head;

public:
    List();
    ~List();
    void insertBeforeFirst(std::string dat);
    void insertAfterLast(std::string dat);
    std::string readFirst();
    std::string removeFirst();
    std::string removeNode(std::string dat);
    void listAll();
};