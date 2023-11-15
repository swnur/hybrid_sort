#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <vector>

void siftDown(std:: vector<int>& list, int i, int n) {
   int current = i;
   int left_child = 2 * current + 1;
   int right_child = 2 * current + 2;

   if (left_child < n && list[left_child] > list[current]) {
      current = left_child;
   }
   if (right_child < n && list[right_child] > list[current]) {
      current = right_child;
   }

   if (current != i) {
      std:: swap(list[current], list[i]);
      siftDown(list, current, n);
   }
}

void buildHeap(std:: vector<int>& list) {
   int n = list.size();
   for (int i = n / 2 - 1; i >= 0; --i) {
      siftDown(list, i, n);
   }
}

void heapSort(std:: vector<int>& list) {
   buildHeap(list);
   int heapSize = list.size(), n = list.size();
   for (int i = 0; i < n - 1; i++) {
      std:: swap(list[0], list[n- 1 - i]);
      heapSize--;
      siftDown(list, 0, heapSize);
   }
}


#endif