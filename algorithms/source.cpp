#include "header.h"
#include "stack.hpp"
#include "queue.hpp"
#include "simpleLinkedList.hpp"
#include "doublyLinkedList.hpp"
#include "circularSimplyLinkedList.hpp"
#include "circularDoublyLinkedList.hpp"
#include "bubbleSort.hpp"
#include "selectionSort.hpp"
#include "insertionSort.hpp"

using namespace DataStructuresStack;
using namespace DataStructuresQueue;
using namespace DataStructuresSimpleList;
using namespace DataStructuresDoublyList;
using namespace DataStructuresCircularSimplyList;
using namespace DataStructuresCircularDoublyList;
using namespace BasicOrderingBubbleSort;
using namespace BasicOrderingSelectionSort;
using namespace BasicOrderingInsertionSort;


int main() {
	int array[] = { 8, 22, 18, 44, 14, 13, 37, 34, 1, 21, 42, 13, 27, 21};
	int size = sizeof(array) / sizeof(array[0]);

	insertionSort<int>* i = new insertionSort<int>(array, size); 

	i->print(); 
	cout << "\n";
	i->sort();
	i->print();
	cout << "\nSize: " << size << "\n";

	delete i;
	_getch();
	return 0;
}