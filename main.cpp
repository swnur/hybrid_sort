#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include "InsertionSort.hpp"
#include "QuickSort.hpp"

std:: ostream& operator<<(std:: ostream& output, std:: vector<int> arr) {
   for (const auto &num: arr) {
      output << num << " ";
   }
   return output;
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

int main() {
   runTestCases();


   return 0;
}