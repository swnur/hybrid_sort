#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <vector>

int partitionWithRandomPivot(std::vector<int>& list, int left, int right) {
   int pivotIndex = left + rand() % (right - left + 1);
   int v = list[pivotIndex];
   int i = left, j = right;
   while(i <= j) {
      while(list[i] < v)
         i++;
      while(list[j] > v)
         j--;
      if (i >= j)
         break;
      std::swap(list[i++], list[j--]);
   }
   return j;
}

int partition(std::vector<int>& list, int left, int right) {
   int v = list[(left + right) / 2];
   int i = left, j = right;
   while(i <= j) {
      while(list[i] < v)
         i++;
      while(list[j] > v)
         j--;
      if (i >= j)
         break;
      std::swap(list[i++], list[j--]);
   }
   return j;
}

void quickSortRun(std::vector<int>& list, int left, int right) {
   if (left < right) {
      int q = partition(list, left, right);
      quickSortRun(list, left, q);
      quickSortRun(list, q + 1, right);
   }
}

void quickSort(std:: vector<int>& list) {
   quickSortRun(list, 0, list.size() - 1);
}

#endif