#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include <vector>

int binarySearch(std::vector<int> list, int key, int left, int right) {
   while(left <= right) {
      int mid = left + (right - left) / 2;
      if (list[mid] == key) {
         return mid;
      } else if (list[mid] < key) {
         left = mid + 1;
      } else {
         right = mid - 1;
      }
   }
   return left;
}

std::vector<int> insertionSort(std::vector<int>& list) {
   int n = list.size();
   for (int i = 1; i < n; ++i) {
      int x = list[i];
      int j = i;
      while (j > 0 && list[j - 1] > x) {
         list[j] = list[j - 1];
         --j;
      }
      list[j] = x;
   }
   return list;
}

std::vector<int> insertionSortWithBinSearch(std::vector<int>& list) {
   int n = list.size();
   for (int i = 1; i < n; i++) {
      int key = list[i];
      int k = binarySearch(list, key, 0, i - 1);
      
      for (int j = i; j > k; --j) {
         list[j] = list[j - 1];
      }

      list[k] = key;
   }
   return list;
}

#endif