#ifndef COUNTINGSORT_HPP
#define COUNTINGSORT_HPP

#include <vector>

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

#endif