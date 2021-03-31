/*
   File Node.h

   Class Node

   Class Node stores integer values for a linked list.

   This file has the Node's interface (header file).

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/

class Node {

    int val;
    Node* next;

public:

    Node(int dat, Node* nxt);
    int getVal();
    Node* getNext();
    void setVal(int dat);
    void setNext(Node* nxt);
};