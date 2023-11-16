#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include "InsertionSort.hpp"
#include "HeapSort.hpp"
#include "QuickSort.hpp"
#include "RadixSort.hpp"

using ns = std::chrono::nanoseconds;

std::vector<int> generateRandomList(int size) {
   std::vector<int> list;
   list.reserve(size);

   std::random_device rd;
   std::mt19937 gen(rd());

   std::uniform_int_distribution<int> dist(0, size);

   for (int i = 0; i < size; ++i) {
      list.push_back(dist(gen));
   }
   
   return list;
}

ns calculateSorting(std::vector<int>& list, void(*sortingAlgorithm)(std::vector<int>&)) {
   std::vector<int> copy(list.size());
   std::copy(list.begin(), list.end(), copy.begin());

   auto start = std::chrono::steady_clock::now();
   sortingAlgorithm(copy);
   auto end = std::chrono::steady_clock::now();

   return std::chrono::duration_cast<ns>(end - start);
}

void runMeasurement(int sizeStep, int maxSize, int maxTimes, std:: ofstream& file_out) {
   file_out << "Size Insertion Heap Quick RadixLSD InsertionSorted HeapSorted QuickSorted RadixLSDSorted InsertionEqual HeapEqual QuickEqual RadixLSDEqual InsertionReversed HeapReversed QuickReversed RadixLSDReversed" << std:: endl; 
   for (int size = sizeStep; size <= maxSize; size += sizeStep) {
      ns total_time_insertion = ns(0);
      ns total_time_heap = ns(0);
      ns total_time_quick = ns(0);
      ns total_time_radix = ns(0);

      ns total_time_insertion_sorted = ns(0);
      ns total_time_heap_sorted = ns(0);
      ns total_time_quick_sorted = ns(0);
      ns total_time_radix_sorted = ns(0);

      ns total_time_insertion_equal = ns(0);
      ns total_time_heap_equal = ns(0);
      ns total_time_quick_equal = ns(0);
      ns total_time_radix_equal = ns(0);

      ns total_time_insertion_reversed = ns(0);
      ns total_time_heap_reversed = ns(0);
      ns total_time_quick_reversed = ns(0);
      ns total_time_radix_reversed = ns(0);

      for (int times = 0; times < maxTimes; ++times) {
         std::vector<int> list = generateRandomList(size);

         total_time_insertion += calculateSorting(list, insertionSort);
         total_time_heap += calculateSorting(list, heapSort);
         total_time_quick += calculateSorting(list, quickSort);
         total_time_radix += calculateSorting(list, radixSortLSD);
         
         for (int i = 0; i < size; ++i) {
            list[i] = i;
         }

         total_time_insertion_sorted += calculateSorting(list, insertionSort);
         total_time_heap_sorted += calculateSorting(list, heapSort);
         total_time_quick_sorted += calculateSorting(list, quickSort);
         total_time_radix_sorted += calculateSorting(list, radixSortLSD);

         std::reverse(list.begin(), list.end());

         total_time_insertion_reversed += calculateSorting(list, insertionSort);
         total_time_heap_reversed += calculateSorting(list, heapSort);
         total_time_quick_reversed += calculateSorting(list, quickSort);
         total_time_radix_reversed += calculateSorting(list, radixSortLSD);

         for (int i = 0; i < size; ++i) {
            list[i] = 1;
         }

         total_time_insertion_equal += calculateSorting(list, insertionSort);
         total_time_heap_equal += calculateSorting(list, heapSort);
         total_time_quick_equal += calculateSorting(list, quickSort);
         total_time_radix_equal += calculateSorting(list, radixSortLSD);

         
      }

      file_out << size << " " 
         << total_time_insertion.count() / maxTimes << " "
         << total_time_heap.count() / maxTimes << " "
         << total_time_quick.count() / maxTimes << " "
         << total_time_radix.count() / maxTimes << " "
         << total_time_insertion_sorted.count() / maxTimes << " "
         << total_time_heap_sorted.count() / maxTimes << " "
         << total_time_quick_sorted.count() / maxTimes << " "
         << total_time_radix_sorted.count() / maxTimes << " "
         << total_time_insertion_equal.count() / maxTimes << " "
         << total_time_heap_equal.count() / maxTimes << " "
         << total_time_quick_equal.count() / maxTimes << " "
         << total_time_radix_equal.count() / maxTimes << " "
         << total_time_insertion_reversed.count() / maxTimes << " "
         << total_time_heap_reversed.count() / maxTimes << " "
         << total_time_quick_reversed.count() / maxTimes << " "
         << total_time_radix_reversed.count() / maxTimes << " "
         << std::endl;
   }
}

int main() {
   const int maxSize = 10000;
   const int maxTimes = 100;
   const int sizeStep = 100;

   std::ofstream file_out("results2.txt");
   if (!file_out.is_open()) {
      std::cerr << "Error opening file." << std::endl;
      return 1;
   }
   
   ns total_time_take_to_run = ns(0);
   auto start = std::chrono::steady_clock::now();
   runMeasurement(sizeStep, maxSize, maxTimes, file_out);
   auto end = std::chrono::steady_clock::now();

   total_time_take_to_run = std::chrono::duration_cast<ns>(end-start);

   std::cout << total_time_take_to_run.count() << std::endl;

   return 0;
}