#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include "InsertionSort.hpp"
#include "QuickSort.hpp"
#include "HeapSort.hpp"

std:: ostream& operator<<(std:: ostream& output, std:: vector<int> arr) {
   for (const auto &num: arr) {
      output << num << " ";
   }
   return output;
}

bool is_heap(std:: vector<int>& arr) {
   for (int i = 0 ; i < arr.size() ; i++) {
        if (2 * i + 1 < arr.size() && arr[i] < arr[2 * i + 1]) {
            return false;
        }
        if (2 * i + 2 < arr.size() && arr[i] < arr[2 * i + 2]) {
            return false;
        }
    }

    return true;
}

void runTestCases() {
   std::map<std::vector<int>, std::vector<int>> testCases = {
      {{4, 11, 3, 6, 0, 1, 8, 5}, {0, 1, 3, 4, 5, 6, 8, 11}},
      {{0, 0, 0, 0, 0, 0, -1}, {-1, 0, 0, 0, 0, 0, 0}},
      {{1, -3, 0}, {-3, 0, 1}},
      {{1, 3, 4, 5, 6, 7, 8, 9, 10}, {1, 3, 4, 5, 6, 7, 8, 9, 10}}
    };

   for (auto& testCase : testCases) {
      std::vector<int> input = testCase.first;
      std::vector<int> expected = testCase.second;

      quickSort(input, 0, input.size() - 1);
      std:: cout << input << std:: endl;
      assert(input == expected);
   }

   std::cout << "All test cases passed!" << std::endl;
}

void testHeap() {
   std:: vector<int> test_arr = {1, 7, 3, 4, 2};
   int n = test_arr.size();
   for (int i = (n - 1) / 2; i >= 0; i--) {
      make_heap(test_arr, n, i);
   }

   std:: cout << test_arr << std:: endl;
   if (!is_heap(test_arr)) {
        std::cout << "make_heap does not work" << std::endl;
   }
}

int main() {
   
   testHeap();

   return 0;
}