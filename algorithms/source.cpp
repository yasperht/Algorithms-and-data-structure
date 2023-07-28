#include "header.h"
#include "stack.hpp"
#include "queue.hpp"
#include "simpleLinkedList.hpp"
#include "doublyLinkedList.hpp"
using namespace DataStructuresStack;
using namespace DataStructuresQueue;
using namespace DataStructuresSimpleList;
using namespace DataStructuresDoublyList;


int main() {
	DoublyLinkedList<string>* list = new DoublyLinkedList<string>();
	
	list->insertFront("Melanie");
	list->insertFront("Leidy"); 
	list->insertFront("Zamira");
	list->insertFront("Laura");
	list->printFordward();
	cout << "Size: " << list->getSize() << "\n";
	cout << "\n";

	list->insertBack("Fernando");
	list->insertBack("Mario");
	list->insertBack("Pepe");
	list->insertBack("Juan");
	list->insertBack("Carlos");
	list->printFordward();
	cout << "Size: " << list->getSize() << "\n";
	cout << "\n";

	list->removeFront();
	list->printFordward();
	cout << "Size: " << list->getSize() << "\n";
	cout << "\n";

	list->removeBack();
	list->printFordward();
	cout << "Size: " << list->getSize() << "\n";
	cout << "\n";

	/*---------------------------------------*/
	cout << "------------------------\n\n";
	list->specificInsert(6, "Lucia");
	list->printFordward();
	cout << "Size: " << list->getSize() << "\n";
	cout << "\n";
	list->specificRemove(2);
	list->printFordward();
	cout << "Size: " << list->getSize() << "\n";
	cout << "\n";

	/*---------------------------------------*/
	cout << "------------------------\n\n";
	list->update(3, "Messi");
	list->printFordward();
	cout << "\n";
	list->search("Lucia");
	cout << "\n";
	list->search("Alejandro");
	cout << "\n";

	delete list;
	_getch();
	return 0;
}