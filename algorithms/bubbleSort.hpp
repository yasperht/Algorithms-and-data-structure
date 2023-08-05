#ifndef __DATA_STRUCTURES_BUBBLE_SORT_HPP__
#define __DATA_STRUCTURES_BUBBLE_SORT_HPP__
#include "header.h"

namespace BasicOrderingBubbleSort {

	template<class T>
	class bubbleSort {
	private:

		void swap(T& a, T& b) {
			T aux = a;
			a = b;
			b = aux;
		}

	public:
		bubbleSort() { }
		~bubbleSort() { }

		void sort(T* array, size_t size) {
			for (int i{}; i < size - 1; i++) {
				for (int j{}; j < size - 1; j++) {
					if (array[j] > array[j + 1]) {
						swap(array[j], array[j + 1]);
					}
				}
			}
		}

		// void sort(vector<T>& myvector) {} --> Forma tradicional

		void sort(vector<T>& v) {
			for (size_t i{}; i < v.size() - 1; i++) {
				for (size_t j{}; j < v.size() - 1; j++) { 
					if (v[j] > v[j + 1]) { swap(v[j], v[j + 1]); }
				}
			}
		}


		void printAscending(T* array, size_t size) {
			for (size_t i = 0; i < size; i++) {
				cout << array[i] << " ";
			}
		}

		void printDescending(T* array, size_t size) {
			for (int i =  size - 1; i >= 0; i--) {
				cout << array[i] << " ";
			}
		}

		void printAscending(vector<T>& v) {
			for (int i{}; i < v.size(); i ++) {
				cout << v[i] << " ";
			}
		}
		void printDescending(vector<T>& v) {
			for (int i = v.size() - 1; i >= 0; i--) {
				cout << v[i] << " ";
			}
		}
	};


}

#endif 
