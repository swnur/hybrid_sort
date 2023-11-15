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

   std::uniform_int_distribution<int> dist(0, 10000);

   for (int i = 0; i < size; ++i) {
      list.push_back(dist(gen));
   }
   
   return list;
}

ns calculateSorting(std::vector<int>& list, void(*sortingAlgorithm)(std::vector<int>&)) {

   auto start = std::chrono::steady_clock::now();
   sortingAlgorithm(list);
   auto end = std::chrono::steady_clock::now();

   return std::chrono::duration_cast<ns>(end - start);
}

void runMeasurement(int sizeStep, int maxSize, int maxTimes, std:: ofstream& file_out, void (*sortingAlgorithm)(std::vector<int>&)) {
   for (int size = sizeStep; size <= maxSize; size += sizeStep) {
      ns total_time_taken = ns(0);
      for (int times = 0; times < maxTimes; ++times) {
         std::vector<int> list = generateRandomList(size);

         total_time_taken += calculateSorting(list, sortingAlgorithm);
         if (!std::is_sorted(list.begin(), list.end())) {
            std::cout << "list is not sorted" << std:: endl;
         }
      }

      file_out << size << " " << total_time_taken.count() / maxTimes << std::endl;
   }
}

int main() {
   const int maxSize = 10000;
   const int maxTimes = 100;
   const int sizeStep = 100;

   std::ofstream file_out("results.txt");
   if (!file_out.is_open()) {
      std::cerr << "Error opening file." << std::endl;
      return 1;
   }
   
   runMeasurement(sizeStep, maxSize, maxTimes, file_out, quickSort);

   return 0;
}