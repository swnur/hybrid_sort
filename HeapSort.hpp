#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <vector>

void make_heap(std:: vector<int>& arr, int n, int i) {
   int parent = i;
   int left_child = 2 * parent + 1;
   int right_child = 2 * parent + 2;

   if (left_child < n && arr[left_child] > arr[parent]) {
      parent = left_child;
   }

   if (right_child <= n && arr[right_child] > arr[parent]) {
      parent = right_child;
   }

   if (parent != i) {
      std:: swap(arr[i], arr[parent]);
      make_heap(arr, n, parent);
   }
}

void buildHeap(std:: vector<int>& arr, int n) {
   for (int i = (n - 1) / 2; i >= 0; i--) {
      make_heap(arr, i, n);
   }
}

void heapSort(std:: vector<int>& arr) {
   int n = arr.size();
   buildHeap(arr, n);
   int heapSize = n;
   for (int i = 0; i < n - 1; i++)  {
      std:: swap(arr[0], arr[n - i - 1]);
      make_heap(arr, i, 0);
   }
}


#endif