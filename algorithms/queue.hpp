#ifndef __DATA_STRUCTURES_QUEUE_HPP__
#define __DATA_STRUCTURES_QUEUE_HPP__

namespace DataStructuresQueue {

	template <class T>
	class Queue {
	private:
		class queueNode {
		public:
			T value;
			queueNode* next;
			queueNode(T value) : value(value), next(nullptr) { }
		};

		queueNode* head;
		queueNode* tail;
		size_t size;
	public: 
		Queue() { this->size = 0; this->head = nullptr; this->tail = nullptr; }
		~Queue(){ while (!isEmpty()) { this->dequeue();}}

		bool isEmpty() { return (this->size == 0); }
		T peekFront() { return this->head->value; }
		T peekBack() { return this->tail->value; }
		size_t getSize() { return this->size; }
	

		void enqueue(T value) {
			queueNode* newNode = new queueNode(value);

			if (isEmpty()) { this->head = this->tail = newNode;}
			else {
				this->tail->next = newNode;
				this->tail = newNode;
			}
			this->size++;
		}

		void dequeue() {
			if (!isEmpty()){
				queueNode* aux = this->head;
				this->head = this->head->next;
				delete aux;

				if (isEmpty()) { this->head = this->tail = nullptr; }

				this->size--;
			}
			else { cout << "The queue is empty,cannot be removed\n"; return; }
		}

		void print() {
			queueNode* current = this->head;
			while (current!= nullptr) {
				if (current == this->tail) {cout << current->value;}
				else {cout << current->value << "->";}
				current = current->next;
			}
		}

	};

}

#endif // !__DATA_STRUCTURES_QUEUE_HPP__
