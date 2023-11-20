#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <algorithm>
#include "InsertionSort.hpp"
#include "QuickSort.hpp"
#include "HeapSort.hpp"
#include "HybridSort.hpp"
#include "RadixSort.hpp"
#include "CountingSort.hpp"

std:: ostream& operator<<(std:: ostream& output, std:: vector<int> arr) {
   for (const auto &num: arr) {
      output << num << " ";
   }
   return output;
}


void runTestCases(void(*sortingAlgorithm)(std::vector<int>&, int, int)) {
   std::map<std::vector<int>, std::vector<int>> testCases = {
      {{4, 11, 3, 6, 0, 1, 8, 5}, {0, 1, 3, 4, 5, 6, 8, 11}},
      {{0, 3, 9400, 230, 430, 2, 0}, {0, 0, 2, 3, 230, 430, 9400}},
      {{1, 1, 1}, {1, 1, 1}},
      {{14, 345, 1904, 200, 1}, {1, 14, 200, 345, 1904}},
      {{1, 3, 4, 5, 6, 7, 8, 9, 10}, {1, 3, 4, 5, 6, 7, 8, 9, 10}}
    };


   for (auto& testCase : testCases) {
      std::vector<int> input = testCase.first;
      std::vector<int> expected = testCase.second;
      
      sortingAlgorithm(input, 0, input.size() - 1);
      
      std::cout << input << std::endl;
      assert(input == expected);
   }

   std::cout << "All test cases passed!" << std::endl;
}

int main() {
   
   // runTestCases(quickSort); // running test cases on Quick Sort
   // runTestCases(heapSort); // running test cases on Heap Sort
   // runTestCases(insertionSort); // running test cases on Insertion Sort
   // runTestCases(radixSort); // running test cases on RadixSort
   // runTestCases(hybridSort); // running test cases on Radix LSD(Least Significant Digit) Sort

   runTestCases(quickSortTest);

   return 0;
}