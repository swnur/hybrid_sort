#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include <vector>

std:: vector<int> insertionSort(std:: vector<int>& arr) {
   size_t n = arr.size();
   for (size_t i = 1; i < n; ++i) {
      int x = arr[i];
      size_t j = i;
      while (j > 0 && arr[j - 1] > x) {
         arr[j] = arr[j - 1];
         --j;
      }
      arr[j] = x;
   }
   return arr;
}


#endif