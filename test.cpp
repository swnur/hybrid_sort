#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <algorithm>
#include "InsertionSort.hpp"
#include "QuickSort.hpp"
#include "HeapSort.hpp"
#include "RadixSort.hpp"
#include "CountingSort.hpp"

std:: ostream& operator<<(std:: ostream& output, std:: vector<int> arr) {
   for (const auto &num: arr) {
      output << num << " ";
   }
   return output;
}


void runTestCases(char sortingAlgorithm) {
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

      switch(sortingAlgorithm) {
         case 'q': 
            quickSort(input);
            break;
         case 'h':
            heapSort(input);
            break;
         case 'i':
            insertionSort(input);
            break;
         case 'b':
            insertionSortWithBinSearch(input);
            break;
         case 'r':
            radixSortLSD(input);
            break;
         case 'c':
            countingSort(input);
            break;
         default:
            std::cout << "Wrong value was given" << std:: endl;
      }

      std::vector<int> result = input;
      std::cout << result << std::endl;
      assert(result == expected);
   }

   std::cout << "All test cases passed!" << std::endl;
}

int main() {
   
   std:: vector<int> arr = { 2, 1, 1, 3, 4, 8, 6, 0, 5, 4 };

   quickSort(arr);

   assert(std::is_sorted(arr.begin(), arr.end()));
   /*
   runTestCases('q'); // running test cases on Quick Sort
   runTestCases('h'); // running test cases on Heap Sort
   runTestCases('i'); // running test cases on Insertion Sort
   runTestCases('b'); // running test cases on Insertion Sort with Binary Search
   runTestCases('r'); // running test cases on Radix LSD(Least Significant Digit) Sort
   */

   return 0;
}