#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP

#include <vector>

int binarySearch(std:: vector<int> arr, int key, int left, int right) {
   while(left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == key) {
         return mid;
      } else if (arr[mid] < key) {
         left = mid + 1;
      } else {
         right = mid - 1;
      }
   }
   return left;
}

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

std:: vector<int> insertionSortWithBinSearch(std:: vector<int>& arr) {
   size_t n = arr.size();
   for (int i = 1; i < n; i++) {
      int key = arr[i];
      int k = binarySearch(arr, key, 0, i - 1);
      
      for (int j = i; j > k; --j) {
         arr[j] = arr[j - 1];
      }

      arr[k] = key;
   }
   return arr;
}

#endif