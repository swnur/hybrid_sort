#ifndef HYBRIDSORT_HPP
#define HYBRIDSORT_HPP

#include "InsertionSort.hpp"
#include "QuickSort.hpp"
#include "RadixSort.hpp"
#include <vector>

void hybridSort(std::vector<int>& list, int left, int right) {
   if (left >= right) 
      return;
   if (right - left <= 50) {
      insertionSort(list, left, right);
   } 
   else {
      int q = partition(list, left, right);
      hybridSort(list, left, q);
      hybridSort(list, q + 1, right);
   }
}


#endif