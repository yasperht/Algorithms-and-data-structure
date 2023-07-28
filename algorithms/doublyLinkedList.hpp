#ifndef __DATA_STRUCTURES_DOUBLY_LIST_HPP__
#define __DATA_STRUCTURES_DOUBLY_LIST_HPP__

namespace DataStructuresDoublyList {

	template<class T>
	class DoublyLinkedList {
	private:
		class Node {
		public:
			T value;
			Node* next;
			Node* prev;

			Node() { }
			Node(T value) : value (value), next(nullptr), prev(nullptr) { }
		};

		int size;
		Node* head;
		Node* tail;

	public:
		DoublyLinkedList() {
			this->size = 0;

			head = new Node();
			tail = new Node();

			this->head->next = this->tail;
			this->head->prev = nullptr;

			this->tail->prev = this->head;
			this->tail->next = nullptr;
		}

		~DoublyLinkedList() {
			while (!isEmpty()) { this->removeFront(); }
			delete head;
			delete tail;
		}

		bool isEmpty() { return (this->head->next == this->tail); }
		int getSize() { return this->size; }
		
	private:
		bool found(T value) {
			if (this->size == 1) {
				Node* current = this->head->next;
				if (current->value == value) { return true; }
				else { return false; }
			}
			else if (this->size == 2) {
				Node* current = this->head->next;
				if (current->value == value || current->next->value == value) { return true; }
				else { return false; }
			}
			else if (this->size == 3) {
				Node* current = this->head->next->next;
				if (current->value == value || current->next->value == value || current->prev->value == value) {
					return true;
				}
				return false;
			}
			else if (this->size == 4){
				Node* current1 = this->head->next->next;
				Node* current2 = this->tail->prev->prev;
				if (current1->value == value || current1->prev->value == value) { return true; }
				else if (current2->value == value || current2->next->value == value) { return true;}
				else { return false; }
			}
			else if (this->size == 5) {
				Node* current1 = this->head->next->next;
				Node* current2 = this->tail->prev->prev;

				if (current1->value == value || current2->value == value) { return true; }
				if (current1->prev->value == value || current1->next->value == value) { return true; }
				if (current2->next->value == value) { return true; }
				else { return false; }

			}
			else if (this->size == 6) {
				Node* current1 = this->head->next->next;
				Node* current2 = this->tail->prev->prev;

				if (current1->value == value || current2->value == value) { return true; }
				if (current1->prev->value == value || current1->next->value == value) { return true; }
				if (current2->prev->value == value || current2->next->value == value) { return true; }
				else { return false; }
			}
			else {
				Node* current1 = this->head->next->next;
				Node* current2 = this->tail->prev->prev;

				while (true) {
					if (current1->value == value || current2->value == value) { return true; }
					if (current1->prev->value == value || current1->next->value == value) { return true; }
					if (current2->prev->value == value || current2->next->value == value) { return true; }

					current1 = current1->next->next;
					current2 = current2->prev->prev;

					if (this->size % 2 == 0) {
						if (current1->next == current2 && (current1->value == value || current2->value == value)) {
							return true;
						}
						return false;
					}
					else {
						if (current1 == current2 && current1->value == value) {
							return true;
						}
						return false;
					}
				}
			}

		}	
		Node* getSpecificNode(int position) {
			Node* temporal;

			if (position == 1 && this->size == 1) { temporal = this->head->next; }
			else if (position == 2) { temporal = this->head->next->next; }
			else if (position == 3){
				Node* current = this->head->next->next;
				temporal = current->next;
			}
			else {
				Node* current = this->head->next->next; /*Position 1*/
				Node* prevCurrent = current->prev;
				Node* nextCurrent = current->next;
				Node* aux;
				int x = 1;

				while (true) {
					if (x == (position - 1)) { temporal = current; break; }
					if ((x - 1) == (position - 1)) { temporal = current->prev; break;}
					if ((x + 1) == (position - 1)) { temporal = current->next; break;}

					current = current->next;
					x++;

					if (current == nextCurrent) {
						aux = current;
						current = current->next;
						 
						x++;

						if (current == aux->next) {
							current = current->next;
							x++;
						}
					}

					prevCurrent = current->prev; 
					nextCurrent = current->next; 
				}
			}

			return temporal;
		}

	public:
		void insertFront(T value) {
			Node* newNode = new Node(value);

			if (isEmpty()) {
				newNode->next = this->tail;
				newNode->prev = this->head;

				this->head->next = newNode;
				this->tail->prev = newNode;
				this->size++;

				return;
			}
			
			if (!found(value)) {
				newNode->next = this->head->next;
				newNode->prev = this->head;
					
				this->head->next->prev = newNode;
				this->head->next = newNode;
				this->size++;
			}
			else { cout << "Duplicate values are not allowed!!\n"; }
		}
		
		void insertBack(T value) {
			Node* newNode = new Node(value);

			if (isEmpty()) {
				newNode->next = this->tail;
				newNode->prev = this->head;

				this->tail->prev = newNode;
				this->head->next = newNode;
				this->size++;

				return;
			}
			
			if (!found(value)) {
				newNode->next = this->tail;
				newNode->prev = this->tail->prev;

				this->tail->prev->next = newNode;
				this->tail->prev = newNode;
				this->size++;
			}
			else { cout << "Duplicate values are not allowed!!\n"; }
		}
		
		void removeFront() {
			if (!isEmpty()) {
				Node* aux = this->head->next;

				this->head->next = aux->next;
				aux->next->prev = this->head;

				delete aux;
				this->size--;
			}
			else { cout << "The list is empty\n"; }
		}

		void removeBack() {
			if (!isEmpty()) {
				Node* aux = this->tail->prev;

				this->tail->prev = aux->prev;
				aux->prev->next = this->tail;

				delete aux;
				this->size--;
			}
			else { cout << "The list is empty\n"; }
		}

		void specificInsert(int position, T value) {
			if (position == 0) { 
				cout << "Please enter a valid index between [ 1 - " << this->size << "].\n"; 
				return;
			}
			
			if (isEmpty()) { cout << "The list is empty\n";  return; }

			if (!found(value)) {
				Node* newNode = new Node(value);
				Node* current = getSpecificNode(position);

				newNode->next = current->next;
				newNode->prev = current;

				current->next->prev = newNode;
				current->next = newNode;
				this->size++;
			}
			else { cout << "Duplicate values are not allowed!!\n"; }
		}

		void specificRemove(int position) {
			if (!isEmpty()) {
				Node* current = getSpecificNode(position);
				Node* aux = current->next; /*El que quiero eliminar*/

				current->next = aux->next;
				aux->next->prev = current;  

				delete aux;
				this->size--;
			}
			else { cout << "The list is empty\n"; }
		}

		void update (int position, T value){
			if (!isEmpty()) {
				Node* current = getSpecificNode(position);
				current->next->value = value;
			}
			cout << "Update node :)\n";
		}

		void search(T value) {
			if (found(value)) { cout << "Value [" << value << "] found\n"; }
			else { cout << "Value is not found\n"; }
		}
		
		void printFordward() {
			Node* current = this->head->next;

			while (current != this->tail) {
				cout << current->value << "->";
				current = current->next;
			}
			cout << "NULL\n";
		}

		void printReverse() {
			Node* current = this->tail->prev;

			while (current != this->head) {
				cout << current->value << "->";
				current = current->prev;
			}
			cout << "NULL\n";
		}

	};
}

#endif // !__DATA_STRUCTURES_DOUBLY_LIST_HPP__ 
