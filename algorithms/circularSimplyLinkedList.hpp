#ifndef __DATA_STRUCTURES_CIRCULAR_SIMPLY_LIST_HPP__
#define __DATA_STRUCTURES_CIRCULAR_SIMPLY_LIST_HPP__
#include "header.h"

namespace DataStructuresCircularSimplyList {

	template<class T>
	class circularSimplyLinkedList {
	private:
		class Node {
		public:
			T value;
			Node* next;

			Node(T value) : value(value), next(nullptr) {}
		};

		Node* header;
		Node* tail;
		int size;
	
	public:
		circularSimplyLinkedList() : header(nullptr), tail(nullptr), size(0) { }
		~circularSimplyLinkedList() { while (!isEmpty()) { removeBegin();} }

		bool isEmpty() { return (this->header == nullptr || this->tail == nullptr); }
		int getSize() { return this->size; }
	private:
		Node* getSpecificNode(int position) {
			if (position < 0 || position > (this->size - 1)) { return nullptr; }

			Node* current = this->header;
			Node* aux = this->header;

			int x{};

			do {
				if (x == position) { return current; }
				x++;
				current = current->next;
			} while (current != aux);
		}
		bool found(T value) {
			if ((!isEmpty())) {
				Node* current = this->header;
				Node* aux = this->header;
				
				if (current->value == value) { return true; }
				else {
					current = current->next;

					while (current != aux) {
						if (current->value == value) { return true; }
						current = current->next;
					}

					return false;
				}
			}
		}

	public:
		void insert(T value) {

			if (isEmpty()) {
				Node* newNode = new Node(value);
				newNode->next = newNode;
				this->header = this->tail = newNode;
				this->size++;
				return;
			}
			
			if (!found(value)){
				Node* newNode = new Node(value);
				this->tail->next = newNode;
				newNode->next = this->header; 
				this->tail = newNode; 
				this->size++;
			}
			else { cout << "Duplicate values are not allowed\n"; }
		}
		
		void insertBegin(T value) {
			if (isEmpty()) { this->insert("value"); return; }

			if (!found(value)) {
				Node* newNode = new Node(value);

				newNode->next = this->header;
				this->header = newNode; 
				this->tail->next = this->header;
				this->size++;
			}
			else { cout << "Duplicate values are not allowed\n"; }
		}

		void insertEnd(T value) {
			if (isEmpty()) { this->insert("value"); return; }

			if (!found(value)) {
				Node* newNode = new Node(value);

				newNode->next = this->header;
				this->tail->next = newNode;
				this->tail = newNode;
				this->size++;
			}
			else { cout << "Duplicate values are not allowed\n"; }
		}

		void specificInsertion(int position, T value) {
			if (position == 0 || position  > (this->size - 1)) {
				cout << "Enter the value between position [1 .. " << this->size - 1 << "]\n";
				return;
			}
			else if (isEmpty()) { cout << "The list is empty\n"; return; }
			else if (found(value)) { cout << "Duplicate values are not allowed\n"; return; }

			Node* newNode  = new Node(value);
			Node* current = getSpecificNode(position - 1);

			newNode->next = current->next;
			current->next = newNode;
			this->size++;
		}
	
		void removeBegin() {
			if (isEmpty()) { return; }

			Node* aux = this->header;

			if (this->size == 1) { this->header = this->tail = nullptr; delete aux; return; }

			this->header = this->header->next;
			this->tail->next = this->header;
			delete aux;

			this->size--;
		}

		void removeEnd() {
			if (isEmpty()) { return; }
			
			if (this->size == 1) { this->removeBegin(); return; }

			Node* current = getSpecificNode(this->size - 2);
			Node* aux = this->tail;

			current->next = this->header;
			this->tail = current;
			delete aux;

			this->size--;
		}

		void specificRemove(int position) {
			if (isEmpty()) { cout << "The list is empty\n"; }
			else if (position < 0 || position > (this->size - 1)) {
				cout << "Enter the value between position [0 .. " << this->size - 1 << "]\n";
			}

			if (position == 0) { removeBegin(); return; }
			else if (position == this->size - 1) { removeEnd(); return; }

			Node* current = getSpecificNode(position - 1);
			Node* aux = current->next;

			current->next = aux->next;
			delete aux;
			this->size--;
		}
	
		void search(T value) {
			if (isEmpty()) { cout << "The list is empty\n"; return; }

			if (found(value)) { cout << "Value [" << value << "] found\n"; }
			else { cout << "Value not found\n"; }
		}

		void print() {
			Node* current = this->header;

			do {
				cout << current->value << "->";
				current = current->next;
			} while (current != this->tail->next);

			cout << "NULL\n";
		}
	};

}

#endif 
