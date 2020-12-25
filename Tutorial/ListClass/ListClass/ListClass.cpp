/* ListClass.cpp : Creating a list class objet
* Date: 24 / 12 / 2020
* Author : Bruno C.Messias
*/

#include <iostream>
//Studing this librarys STl
#include <vector> 
#include <list>

class list {
public:
	list():head(nullptr), cursor(nullptr){} //constructor initializer to nullptr, its better than only 0
	void prepend(int n); //insert at front value n
	int get_element() { return cursor->d; }
	void advance() { cursor = cursor->next; }
	void print();
private:
	list_element* head;
	list_element* cursor;
};

void list::prepend(int n)
{
	if (head == nullptr)
		cursor = head = new list_element(n, head);
	else
		head = new list_element(n, head);
}

void list::print()
{
	list_element* h = head;
	while (h != 0)
	{
		std::cout << h -> d << ",";
		h = h -> next;
	}
	std::cout << "###" << std::endl;
}

int main()
{
	list a, b;
	a.prepend(9); a.prepend(8);
	std::cout << "list a" << std::endl;
	a.print();
	for (int i = 0; i < 40; i++)
		b.prepend(i * i);
	std::cout << " list b " << std::endl;
	b.print();

	return 0;
}