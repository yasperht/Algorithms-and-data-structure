#include "header.h"
#include "stack.hpp"
#include "queue.hpp"
#include "simpleLinkedList.hpp"
#include "doublyLinkedList.hpp"
#include "circularSimplyLinkedList.hpp"
#include "circularDoublyLinkedList.hpp"

using namespace DataStructuresStack;
using namespace DataStructuresQueue;
using namespace DataStructuresSimpleList;
using namespace DataStructuresDoublyList;
using namespace DataStructuresCircularSimplyList;
using namespace DataStructuresCircularDoublyList;


int main() {
	circularDoublyLinkedList<string>* list = new circularDoublyLinkedList<string>();

	list->insert("Melanie");
	list->insert("Leidy");
	list->insert("Laura");
	list->insert("Paola");
	list->printFordward();
	cout << "Size: " << list->getSize() << "\n";
	cout << "\n";

	list->insertBegin("Miriam");
	list->printFordward();
	cout << "Size: " << list->getSize() << "\n";
	cout << "\n";

	list->insertEnd("Luz");
	list->printFordward();
	cout << "Size: " << list->getSize() << "\n";
	cout << "\n";

	list->specificInsertion(3, "Lucia");
	list->printFordward();
	cout << "Size: " << list->getSize() << "\n";

	/*Removing*/
	cout << "\n\n";
	cout << "Removing the list\n";

	list->removeBegin();
	list->printFordward();
	cout << "Size: " << list->getSize() << "\n";

	list->removeEnd();
	list->printFordward();
	cout << "Size: " << list->getSize() << "\n";

	list->specificRemove(3);
	list->printFordward();
	cout << "Size: " << list->getSize() << "\n";

	list->search("Lucia");
	cout << "\n\n";
	list->printFordward();
	list->printReverse();
	cout << "Size: " << list->getSize() << "\n";

	delete list;
	_getch();
	return 0;
}