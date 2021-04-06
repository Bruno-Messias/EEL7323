
#include "List.h"

List::List() {
	head = 0;
}

List::~List() {
	Node* cursor = head;
	while (head) {
		cursor = cursor->getNext();
		delete head;
		head = cursor;
	}
	head = 0; // Officially empty
}

void List::insertAfterLast(int newYear, int newMonth, int newDay, int newHour, int newMin, int newSec, char newEvent)
 {
	Node* p = head;
	Node* q = head;

	if (head == 0)
		head = new Node(newYear,newMonth, newDay, newHour, newMin, newSec, newEvent, head);
		
	else 
	{
		while (q != 0) 
		{
			p = q;
			q = p->getNext();
		}
		p->setNext(new Node(newYear,newMonth, newDay, newHour, newMin, newSec, newEvent, 0));
	}
}

void List::removeFirst() 
{
	if (head != 0) {
		Node* oldHead = head;
		head = head->getNext();
		delete oldHead;
	}
}

void List::listAll() {
  Node* aux = head;
  while (aux != 0){
     cout << aux->getEvent() << endl;
     aux = aux->getNext();
  }
}