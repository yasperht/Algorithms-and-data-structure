#ifndef __DATA_STRUCTURES_INSERTION_SORT_HPP__
#define __DATA_STRUCTURES_INSERTION_SORT_HPP__

namespace BasicOrderingInsertionSort {

	template <class T>
	class insertionSort {
	private:
		void swap(T& a, T& b) {
			T aux = a;
			a = b;
			b = aux;
		}

		T* array;
		int size;
	public:
		insertionSort(T* array, int size): array(array), size(size) { }
		~insertionSort() { }

		void sort() {
			for (int i{}; i < this->size - 1; i++) { 
				for (int j = i; j >= 0; j--) {
					if (this->array[j] > this->array[j + 1]) { swap(this->array[j], this->array[j + 1]); } /*Extract = array[j + 1]*/
					else { break; }
				}
			}
		}
			
		void print() {
			for (int i{}; i < this->size; i++) {
				cout << this->array[i] << " ";
			}
		}
	};
}

#endif // !__DATA_STRUCTURES_INSERTION_SORT_HPP__
