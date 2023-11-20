#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include "InsertionSort.hpp"
#include <vector>

int findMedianIndex(std::vector<int>& arr, int left, int right) {
   int mid = left + (right - left) / 2;

   if ((arr[left] <= arr[mid] && arr[mid] <= arr[right]) || (arr[right] <= arr[mid] && arr[mid] <= arr[left])) {
      return mid; 
   } else if ((arr[left] <= arr[right] && arr[right] <= arr[mid]) || (arr[mid] <= arr[right] && arr[right] <= arr[left])) {
      return right; 
   }
   return left; 
}


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

int partitionWithFirstPivot(std::vector<int>& list, int left, int right) {
   int v = list[left];
   int i = left,j = right;
   while(i <= j) {
      while(list[i] < v)
         i++;
      while(list[j] > v)
         j--;
      if (j >= i)
         break;
      std::swap(list[i++], list[j--]);
   }

   return j;
}

void quickSort(std::vector<int>& list, int left, int right) {
   if (left < right) {
      int q = partition(list, left, right);
      quickSort(list, left, q);
      quickSort(list, q + 1, right);
   }
}

void quickSortTest(std::vector<int>& list, int left, int right) {
   if (left < right) {
      if (right - left <= 50) {
         insertionSort(list, left, right);
      }
      int med = findMedianIndex(list, left, right);
      std::swap(list[med], list[(left + right) / 2]);
      int q = partition(list, left, right);
      quickSort(list, left, q);
      quickSort(list, q + 1, right);
   }
}


#endif