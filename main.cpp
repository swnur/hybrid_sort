#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include "InsertionSort.hpp"
#include "QuickSort.hpp"
#include "HeapSort.hpp"
#include "RadixSort.hpp"

std:: ostream& operator<<(std:: ostream& output, std:: vector<int> arr) {
   for (const auto &num: arr) {
      output << num << " ";
   }
   return output;
}


void runTestCases() {
   std::map<std::vector<int>, std::vector<int>> testCases = {
      {{4, 11, 3, 6, 0, 1, 8, 5}, {0, 1, 3, 4, 5, 6, 8, 11}},
      // {{0, 0, 0, 0, 0, 0, -1}, {-1, 0, 0, 0, 0, 0, 0}},
      // {{1, -3, 0}, {-3, 0, 1}},
      {{1, 3, 4, 5, 6, 7, 8, 9, 10}, {1, 3, 4, 5, 6, 7, 8, 9, 10}}
    };

   for (auto& testCase : testCases) {
      std::vector<int> input = testCase.first;
      std::vector<int> expected = testCase.second;

      // quickSort(input, 0, input.size() - 1);
      // heapSort(input);
      // insertionSort(input);
      radixSort(input);
      // std:: vector<int> result = countingSort(input);
      std:: cout << input << std:: endl;
      assert(input == expected);
   }

   std::cout << "All test cases passed!" << std::endl;
}

int main() {
   
   std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    
   std::cout << "Original array: ";
   std:: cout << arr << std:: endl;

   radixSort(arr);

   std::cout << "Sorted array: ";
   std::cout << arr << std:: endl;

   runTestCases();

   return 0;
}