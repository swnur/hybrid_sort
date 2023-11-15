#ifndef RADIXSORT_HPP
#define RADIXSORT_HPP

#include <vector>
#include <algorithm>

std:: vector<int> countingSort(std:: vector<int>& arr) {
    int minElement = *std::min_element(arr.begin(), arr.end());
    int maxElement = *std::max_element(arr.begin(), arr.end());
    std::vector<int> count(maxElement - minElement + 1, 0);

    for (int num : arr) {
        count[num - minElement]++;
    }

    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    std::vector<int> output(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--) {
        int current = arr[i];
        int positionInArray = count[current - minElement] - 1;
        output[positionInArray] = current;
        count[current - minElement]--;
    }

    return output;
}

std:: vector<int> countingSortForRadixSort(std:: vector<int>& arr, int exp) {
    std::vector<int> count(10, 0);
    for (int num : arr) {
        count[(num / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    std::vector<int> output(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--) {
        int current = arr[i];
        int positionInArray = count[(current / exp) % 10] - 1;
        output[positionInArray] = current;
        count[(current / exp) % 10]--;
    }

    return output;
}


void radixSort(std:: vector<int>& arr) {
    int maxNum = *std::max_element(arr.begin(), arr.end());
    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        arr = countingSortForRadixSort(arr, exp);
    }
}

#endif