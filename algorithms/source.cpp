#include "header.h"
#include "stack.hpp"
#include "queue.hpp"
#include "simpleLinkedList.hpp"
using namespace DataStructuresStack;
using namespace DataStructuresQueue;
using namespace DataStructuresSimpleList;


int main() {
	simpleLinkedList<string>* list = new simpleLinkedList<string>();

	list->insert("Melanie");
	list->insert("Zamira");
	list->insert("Leidy");
	list->insert("Laura");
	list->insert("Paola");
	list->print();
	cout << "\nSize: " << list->getSize() << "\n";
	
	cout << "\n\n";
	list->specificInsertion(1, "Daniela");
	list->print();
	cout << "\nSize: " << list->getSize() << "\n";

	cout << "\n\n";
	list->removeFront();
	list->print();
	cout << "\nSize: " << list->getSize() << "\n";

	cout << "\n\n";
	list->insert("Leidy");
	list->print();

	cout << "\n\n";
	list->removeIn(1);
	list->print();
	cout << "\nSize: " << list->getSize() << "\n";

	cout << "\n\n";
	list->search("Melanie");
	list->search("Paola");

	delete list;
	_getch();
	return 0;
}