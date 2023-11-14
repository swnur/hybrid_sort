#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <vector>

int partition(std:: vector<int>& arr, int left, int right) {
   int v = arr[(left + right) / 2];
   int i = left, j = right;
   while(i <= j) {
      while(arr[i] < v)
         i++;
      while(arr[j] > v)
         j--;
      if (i >= j)
         break;
      std:: swap(arr[i++], arr[j--]);
   }
   return j;
}

void quickSort(std:: vector<int>& arr, int left, int right) {
   if (left < right) {
      int q = partition(arr, left, right);
      quickSort(arr, left, q);
      quickSort(arr, q + 1, right);
   }
}

#endif