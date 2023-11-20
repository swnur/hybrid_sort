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
#include "HybridSort.hpp"

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

ns calculateSorting(std::vector<int>& list, void(*sortingAlgorithm)(std::vector<int>&, int, int)) {
   std::vector<int> copy(list.size());
   std::copy(list.begin(), list.end(), copy.begin());

   auto start = std::chrono::steady_clock::now();
   sortingAlgorithm(copy, 0, copy.size() - 1);
   auto end = std::chrono::steady_clock::now();

   return std::chrono::duration_cast<ns>(end - start);
}

void runMeasurement(int sizeStep, int maxSize, int maxTimes, std:: ofstream& file_out) {
   file_out << "Size Insertion Heap Quick RadixLSD Hybrid InsertionSorted HeapSorted QuickSorted RadixLSDSorted HybridSorted InsertionEqual HeapEqual QuickEqual RadixLSDEqual HybridEqual InsertionReversed HeapReversed QuickReversed RadixLSDReversed HybridReversed" << std:: endl; 
   for (int size = sizeStep; size <= maxSize; size += sizeStep) {
      if (size == 100) {
         sizeStep = 100;
      } else if (size == 1000) {
         sizeStep = 500;
      } else if (size == 10000) {
         sizeStep = 1000;
      }
      // ns total_time_insertion = ns(0);
      // ns total_time_heap = ns(0);
      // ns total_time_quick = ns(0);
      // ns total_time_radix = ns(0);
      // ns total_time_hybrid = ns(0);

      ns total_time_insertion_part = ns(0);
      ns total_time_heap_part = ns(0);
      ns total_time_quick_part = ns(0);
      ns total_time_radix_part = ns(0);
      ns total_time_hybrid_part = ns(0);

      for (int times = 0; times < maxTimes; ++times) {
         std::vector<int> list(size);

         for (int i = 0; i < size; ++i) {
            list[i] = i;
         }
         
         // total_time_insertion += calculateSorting(list, insertionSort);
         // total_time_heap += calculateSorting(list, heapSort);
         // total_time_quick += calculateSorting(list, quickSort);
         // total_time_radix += calculateSorting(list, radixSortLSD);
         // total_time_hybrid += calculateSorting(list, hybridSort);

         std::swap(list[0], list[list.size() - 1]);

         total_time_insertion_part += calculateSorting(list, insertionSort);
         total_time_heap_part += calculateSorting(list, heapSort);
         total_time_quick_part += calculateSorting(list, quickSort);
         total_time_radix_part += calculateSorting(list, radixSortLSD);
         total_time_hybrid_part += calculateSorting(list, hybridSort);
      }

      file_out << size << " " 
         // << total_time_insertion.count() / maxTimes << " "
         // << total_time_heap.count() / maxTimes << " "
         // << total_time_quick.count() / maxTimes << " "
         // << total_time_radix.count() / maxTimes << " "
         // << total_time_hybrid.count() / maxTimes << " "
         << total_time_insertion_part.count() / maxTimes << " "
         << total_time_heap_part.count() / maxTimes << " "
         << total_time_quick_part.count() / maxTimes << " "
         << total_time_radix_part.count() / maxTimes << " "
         << total_time_hybrid_part.count() / maxTimes
         << std::endl;
   }
}

int main() {
   const int maxSize = 20000;
   const int maxTimes = 100;
   const int sizeStep = 10;

   std::ofstream file_out("partially_sorted.txt");
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