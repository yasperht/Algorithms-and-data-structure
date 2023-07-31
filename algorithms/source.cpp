#include "header.h"
#include "stack.hpp"
#include "queue.hpp"
#include "simpleLinkedList.hpp"
#include "doublyLinkedList.hpp"
#include "circularSimplyLinkedList.hpp"

using namespace DataStructuresStack;
using namespace DataStructuresQueue;
using namespace DataStructuresSimpleList;
using namespace DataStructuresDoublyList;
using namespace DataStructuresCircularSimplyList;


int main() {
	circularSimplyLinkedList<string>* list = new circularSimplyLinkedList<string>();

	list->insert("Melanie");
	list->insert("Leidy");
	list->insert("Zamira");
	list->insert("Laura");
	list->insert("Paola");
	list->print();
	cout << "Size: " << list->getSize() << "\n";
	
	cout << "---------------------------------\n\n";
	list->insertBegin("Merlyn");
	list->print();
	cout << "Size: " << list->getSize() << "\n";

	cout << "\n\n";
	list->insertEnd("Amanda");
	list->print();
	cout << "Size: " << list->getSize() << "\n";

	cout << "---------------------------------\n\n";
	list->specificInsertion(3, "Lucia");
	list->print();
	cout << "Size: " << list->getSize() << "\n";

	cout << "\n\n";
	cout << "Deleting the list\n";
	list->specificRemove(5);
	list->print();
	cout << "Size: " << list->getSize() << "\n";

	cout << "\n\n";
	list->removeBegin();
	list->print();
	cout << "Size: " << list->getSize() << "\n";

	list->removeEnd();
	list->print();
	cout << "Size: " << list->getSize() << "\n";

	list->search("Lucia");
	

	delete list;
	_getch();
	return 0;
}