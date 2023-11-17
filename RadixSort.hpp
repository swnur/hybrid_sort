#ifndef RADIXSORT_HPP
#define RADIXSORT_HPP

#include <vector>
#include <algorithm>

std::vector<int> countingSortDigit(std::vector<int>& list, int exp) {
    std::vector<int> count(10, 0);
    for (int value : list) {
        count[(value / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    std::vector<int> output(list.size());

    for (int i = list.size() - 1; i >= 0; i--) {
        int current = list[i];
        int positionInArray = count[(current / exp) % 10] - 1;
        output[positionInArray] = current;
        count[(current / exp) % 10]--;
    }

    return output;
}

void radixSortLSD(std::vector<int>& list, int left, int right) {
    int maxNum = *std::max_element(list.begin(), list.end());
    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        list = countingSortDigit(list, exp);
    }
}

std::vector<int> countingSortByBit(std::vector<int>& list, int mask, int shift) {
   int arr[2] = {0, 0};

   for (int value: list) {
      arr[(value & mask) >> shift] += 1;
   }

   arr[1] = list.size();

   std::vector<int> res(list.size());

   for (int i = list.size() - 1; i >= 0; --i) {
        res[--arr[(list[i] & mask) >> shift]] = list[i];
    }

   return res;
}

void radixSort(std::vector<int>& list, int left, int right) {
   int maxNum = *std::max_element(list.begin(), list.end());
   int shift = 0;
   for (int mask = 1; mask <= maxNum; mask *= 2) {
      list = countingSortByBit(list, mask, shift);
      shift++; 
   }
}


#endif