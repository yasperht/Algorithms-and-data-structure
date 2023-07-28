#ifndef __DATA_STRUCTURES_STACK_HPP__
#define __DATA_STRUCTURES_STACK_HPP__

#include "header.h"
#include <functional>

namespace DataStructuresStack {

	template <class T>
	class Stack {
	private:
		class stackNode {
		public:
			T value;
			stackNode* next;
			stackNode(T value) : value(value), next(nullptr) { }
		};

		stackNode* top;
		size_t size;

	public:
		Stack() { this->top = nullptr; this->size = 0; }
		~Stack() { while (!isEmpty()) { pop(); } }

		size_t getSize() { return this->size; }
		bool isEmpty() { return (this->top == nullptr); }

		T peek() { return this->top->value; }

		void push(T value) {
			stackNode* newNode = new stackNode(value);
			newNode->next = this->top;
			this->top = newNode;
			this->size++;
		}

		void pop() {
			if (isEmpty()) { cout << "The Stack is empty, cannot be removed\n"; return; }

			stackNode* aux = this->top;
			this->top = this->top->next;
			delete aux;
			this->size--;
		}

		void print() {
			stackNode* current = this->top;

			while (current != nullptr) {
				cout << current->value << "->";
				current = current->next;
			}
			cout << "NULL\n";
		}

	};
	
}

#endif;