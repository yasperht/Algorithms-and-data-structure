#ifndef __DATA_STRUCTURES_SIMPLE_LIST_HPP__
#define __DATA_STRUCTURES_SIMPLE_LIST_HPP__

namespace DataStructuresSimpleList {

	template<class T>
	class simpleLinkedList {
	private:
		class Node {
		public:
			T value;
			Node* next;
			Node(T value) : value(value), next(nullptr) { }
		};

		Node* head;
		size_t size;

	public: 
		simpleLinkedList() : head(nullptr), size(0) { }
		~simpleLinkedList() { while (!isEmpty()) { this->removeFront(); } }

		size_t getSize() { return this->size; }

	private:
		bool isEmpty() { return (this->head == nullptr); }
		Node* getLastNode() {
			if (this->head == nullptr && this->size == 0) { return nullptr; }

			Node* current = this->head;
			Node* last;

			while (current != nullptr) {
				last = current;
				current = current->next;
			}

			return last;
		}
		Node* getSpecificNode(int position) {
			if (position > (this->size - 1) && (isEmpty())) { return nullptr;}

			Node* current = this->head;
			int x = 0;

			while (current != nullptr) {
				if (x == position) { return current; }
				x++;
				current = current->next;
			}
		}
		bool thisExist(T value) {
			if ((isEmpty()) || this->size == 0) { return false; }
			
			Node* current = this->head;

			while (current != nullptr) {
				if (current->value == value) { return true; }
				current = current->next;
			}

			return false;
		}

	public:
		void insert(T value) {
			Node* newNode = new Node(value);

			if (!thisExist(value)) {
				if (isEmpty()) { this->head = newNode; }
				else {
					Node* last = getLastNode();
					last->next = newNode;
				}

				this->size++;
			}
			else { cout << "No duplicate value allowed!\n"; }
		}

		void specificInsertion(int position, T value) {
			if (getSpecificNode(position) == nullptr) {
				cout << "Cannot be inserted in an invalid position\n";
				return;
			}

			if (!thisExist(value)) {
				Node* newNode = new Node(value);
				Node* current = getSpecificNode(position); /*Después de este nodo insertamos el nodo nuevo*/
				Node* aux = getSpecificNode(position)->next;

				current->next = newNode;
				newNode->next = aux;

				this->size++;
			}
			else { cout << "No duplicate value allowed!\n";}	
		}

		void removeFront() {
			if (isEmpty()) { cout << "The list is empty :(\n"; return; }
			
			Node* aux = this->head;
			this->head = this->head->next;
			delete aux;
			this->size--;
		}

		void removeIn(int position) {
			if (getSpecificNode(position) == nullptr) { 
				cout << "The list is empty or the position is invalid :(\n"; return; 
			}

			Node* nodeDelete = getSpecificNode(position);
			Node* sentinel = this->head;

			if (sentinel == nodeDelete) { this->head = this->head->next; }
			else {
				while (sentinel->next != nodeDelete) { sentinel = sentinel->next;}
				sentinel->next = nodeDelete->next;
			}
			
		
			delete nodeDelete; 
			this->size--;
		}

		void search(T value) {
			if ((isEmpty()) || this->size == 0) { cout << "The list is empty :(\n"; return; }

			if (thisExist(value)) { cout << "Value [" << value << "] found\n"; }
			else { cout << "Value not found\n"; }
		}
	
		void print() {
			Node* current = this->head;

			while (current != nullptr) {
				cout << current->value << "->";
				current = current->next;
			}
			cout << "NULL\n";
		}
	};
}

#endif // !__DATA_STRUCTURES_SIMPLE_LIST_HPP__
