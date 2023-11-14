#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <vector>

void siftDown(std:: vector<int>& arr, int i, int n) {
   int current = i;
   int left_child = 2 * current + 1;
   int right_child = 2 * current + 2;

   if (left_child < n && arr[left_child] > arr[current]) {
      current = left_child;
   }
   if (right_child < n && arr[right_child] > arr[current]) {
      current = right_child;
   }

   if (current != i) {
      std:: swap(arr[current], arr[i]);
      siftDown(arr, current, n);
   }
}

void buildHeap(std:: vector<int>& arr) {
   int n = arr.size();
   for (int i = n / 2 - 1; i >= 0; --i) {
      siftDown(arr, i, n);
   }
}

void heapSort(std:: vector<int>& arr) {
   buildHeap(arr);
   int heapSize = arr.size(), n = arr.size();
   for (int i = 0; i < n - 1; i++) {
      std:: swap(arr[0], arr[n- 1 - i]);
      heapSize--;
      siftDown(arr, 0, heapSize);
   }
}


#endif