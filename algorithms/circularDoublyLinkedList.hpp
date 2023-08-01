#ifndef __DATA_STRUCTURES_CIRCULAR_DOUBLY_LIST_HPP__
#define __DATA_STRUCTURES_CIRCULAR_DOUBLY_LIST_HPP__  

namespace DataStructuresCircularDoublyList {

	template<class T>
	class circularDoublyLinkedList {
	private:
		class Node {
		public:
			T value;
			Node* next;
			Node* prev;

			Node() { }
			Node(T value): value(value), next(nullptr), prev(nullptr) {}
		};

		Node* header;
		int size;

	public:
		circularDoublyLinkedList(): header(nullptr), size(0) { }
		~circularDoublyLinkedList() { while (!isEmpty()) { removeBegin(); }}

		bool isEmpty() { return (this->header == nullptr || this->size == 0); }
		int getSize() { return this->size; }

	private:
		bool found (T value){
			if (!isEmpty()) {
				if (this->header->value == value || this->header->prev->value == value) { return true; }

				Node* current = this->header->next; 
				Node* aux = this->header->prev;
				Node* tail = aux->prev; 
				
				Node* aux2 = current; 
				aux = tail;

				/*Lambda Definition*/
				auto validation = [value](Node* current, Node* tail) -> bool {
					if (current->value == value || tail->value == value) { return true; } 
					else if (current->next->value == value || current->prev->value == value) { return true; } 
					else if (tail->next->value == value || tail->prev->value == value) { return true; } 
					else { return false; }
				};

				auto check = [=](Node* current, Node* tail) -> bool {
					if (current->next == tail || current == tail) { return true; }
					else { return false; }
				};


				/*Body*/
				while (true) {
					if (check(current, tail)) { 
						if (validation(current, tail)) { return true; } 
						return false; 
					}


					if (validation(current, tail)) { return true; }
					else {
						current = current->next;
						tail = tail->prev;

						if (check(current, tail)) {
							if (validation(current, tail)) { return true; }
							return false;
						}
						
						if (current == aux2->next && tail == aux->prev) {
							aux2 = current;
							aux = tail;

							current = current->next;
							tail = tail->prev;

							if (check(current, tail)) { 
								if (validation(current, tail)) { return true; } 
								return false; 
							}

							if (current == aux2->next && tail == aux->prev) {
								aux2 = current;
								aux = tail;

								current = current->next;
								tail = tail->prev;
							}
						}

					}

				}
			}
			else { cout << "The list is empty:\n"; }

			return false;
		}

		Node* getSpecificNode(int position){
			if (isEmpty() || position < 0 || position >= this->size) {
				return nullptr;
			}

			Node* current = this->header;
			Node* tail = this->header->prev;
			int x{}, y = this->size - 1;

			while (true) {
				if (x == position) { return current;}
				else if (y == position) { return tail; }

				x++; y--;
				current = current->next;
				tail = tail->prev;

				if (x + 1 == y) {
					if (x == position) { return current; }
					else if (y == position) { return tail; }
					else { return nullptr; }
				}
				else if (x == y) {
					if (x == position) { return current; }
					else { return nullptr; }
				}
			}

			return nullptr;
		}

	public:
		void insert(T value) {
			Node* newNode = new Node(value);

			if (isEmpty()) {
				this->header = newNode;
				this->header->next = newNode;
				this->header->prev = newNode;

				this->size++; 
				return;
			}
			
			if (!found(value)){
				this->header->prev->next = newNode;
				newNode->prev = this->header->prev;

				this->header->prev = newNode;
				newNode->next = this->header;
				this->size++;
			}
			else { cout << "Duplicate values are not allowed\n"; }
		}
		
		void insertBegin(T value) {
			if (isEmpty()) { insert(value); return; }

			if (!found(value)) {
				Node* newNode = new Node(value);

				newNode->next = this->header;
				newNode->prev = this->header->prev;

				this->header->prev->next = newNode;
				this->header->prev = newNode;
				this->header = newNode;

				this->size++;
			}
			else { cout << "Duplicate values are not allowed\n"; }
			
		}

		void insertEnd(T value) {
			if (isEmpty()) { insert(value); return; } 

			if (!found(value)) {
				Node* newNode = new Node(value);

				this->header->prev->next = newNode;
				newNode->prev = this->header->prev;

				this->header->prev = newNode;
				newNode->next = this->header;

				this->size++;
			}
			else { cout << "Duplicate values are not allowed\n"; }
		}
	
		void specificInsertion(int position, T value) {
			if (isEmpty() == true || (position <= 0 || position > (this->size - 1))) { return; }

			Node* newNode = new Node(value);
			Node* current = getSpecificNode(position - 1);

			newNode->next = current->next; 
			current->next->prev = newNode;

			newNode->prev = current;
			current->next = newNode;
			this->size++;
		}

		void removeBegin() {
			Node* aux = this->header;

			if (this->size == 1) { this->header = nullptr;}
			else {
				this->header = this->header->next;
				this->header->prev = aux->prev;
				aux->prev->next = this->header;
			}

			delete aux;
			this->size--;
		}
	
		void removeEnd() {
			if (isEmpty()) { return; }

			Node* aux = this->header->prev;

			if (this->size == 1) { this->header = nullptr; delete aux; return; }

			this->header->prev = this->header->prev->prev;
			this->header->prev->next = this->header;

			delete aux;
			this->size--;
		}
	
		void specificRemove(int position) {
			if ( isEmpty() == true || this->size < 3 || (position <= 0 || position > (this->size - 2))) { 
				cout << "This position is invalid\n";
				return; 
			}

			Node* aux = getSpecificNode(position);
			Node* current = getSpecificNode(position - 1);

			current->next = aux->next;
			aux->next->prev = current;
			
			delete aux;
			this->size--;
		}
	
		void search(T value) {
			if (isEmpty()) { cout << "The list is empty\n"; return; }

			if (found(value)) { cout << "Value [" << value << "] found\n"; }
			else { cout << "Value not found\n"; }
		}
		
		void printFordward() {
			if (isEmpty()) { cout << "The list is empty\n"; return; }

			Node* current = this->header;
			cout << "[" << this->header->prev->value << "]<-"; 

			do {
				cout << current->value << "->";
				current = current->next;
			} while (current != this->header);

			cout << "[" << this->header->value << "]\n";
		}

		void printReverse() {
			Node* current = this->header->prev;
			Node* aux = this->header->prev;

			cout << "[" << aux->next->value << "]<-";

			do {
				cout << current->value << "->";
				current = current->prev;
			} while (current != aux);
			cout << "[" << aux->value << "]\n";
		}
	};
}

#endif 
