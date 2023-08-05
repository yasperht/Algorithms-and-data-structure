#ifndef __DATA_STRUCTURES_SELECTION_SORT_HPP__
#define __DATA_STRUCTURES_SELECTION_SORT_HPP__
#include "header.h"

namespace BasicOrderingSelectionSort {

	template<class T>
	class selectionSort {
	private:
		void swap(T& a, T& b) {
			T aux = a;
			a = b;
			b = aux;
		}

	public:
		selectionSort() { }
		~selectionSort() { }

		void sort(T* array, int size) {
			int index_minimum = 0;

			for (int i{}; i < size - 1; i++) {
				index_minimum = i;

				for (int j = i + 1; j < size; j++) {
					if (array[j] < array[index_minimum]) { index_minimum = j; } 
				}

				swap(array[i], array[index_minimum]); 
			}
		}

		void printAcending(T* array, int size) {
			for (int i{}; i < size; i++) {
				cout << array[i] << " ";
			}
		}

		void printDescending(T* array, int size) {
			for (int i = size - 1; i >= 0; i--) {
				cout << array[i] << " ";
			}
		}
	};
}

#endif // !__DATA_STRUCTURES_SELECTION_SORT_HPP__
