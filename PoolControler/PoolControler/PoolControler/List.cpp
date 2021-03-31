
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

void List::insertBeforeFirst(std::string dat) {
	head = new Node(dat, head);
}

void List::insertAfterLast(std::string dat) {
	Node* p = head;
	Node* q = head;

	if (head == 0)
		head = new Node(dat, head);
	else {
		while (q != 0) {
			p = q;
			q = p->getNext();
		}
		p->setNext(new Node(dat, 0));
	}
}

std::string List::readFirst() {
	return head->getVal();
}

std::string List::removeFirst() {
	std::string retval = "";
	if (head != 0) {
		cout << "Removendo: " << head << endl;
		cout << "e fica:" << head->getVal() << endl;
		retval = head->getVal();
		Node* oldHead = head;
		head = head->getNext();
		delete oldHead;
	}
	return retval;
}

void List::listAll() {
	Node* aux = head;
	while (aux != 0) {
		cout << aux->getVal() << endl;
		aux = aux->getNext();
	}
}