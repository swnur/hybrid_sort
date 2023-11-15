#ifndef COUNTINGSORT_HPP
#define COUNTINGSORT_HPP

#include <vector>

void countingSort(std::vector<int>& list) {
    int minElement = *std::min_element(list.begin(), list.end());
    int maxElement = *std::max_element(list.begin(), list.end());
    std::vector<int> count(maxElement - minElement + 1, 0);

    for (int& value : list) {
        count[value - minElement]++;
    }

    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    std::vector<int> output(list.size());

    for (int i = list.size() - 1; i >= 0; i--) {
        int current = list[i];
        int positionInArray = count[current - minElement] - 1;
        output[positionInArray] = current;
        count[current - minElement]--;
    }

   std:: copy(output.begin(), output.end(), list.begin());
}

#endif