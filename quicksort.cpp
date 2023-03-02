#include <iostream>
#include <string>
#include <vector>
#include <cmath>

// Splits string with space seperated numbers
// Doesn't work with multiple spaces in between numbers or space in beginning (i.e. application specific)
void split(std::vector<int>& values, const std::string& string) {
    values.reserve((string.length() + 1) / 2);

    std::string buffer = "";
    for (int i = 0; i < string.length(); i++) {
        if (string[i] == ' ' || i == string.length() - 1) {
            if (i == string.length() - 1)
                buffer.push_back(string[i]);
            values.push_back(stoi(buffer));
            buffer.clear();
        }
        else
            buffer.push_back(string[i]);
    }
}

void swap(std::vector<int>& list, int index1, int index2) {
    int temp = list[index1];
    list[index1] = list[index2];
    list[index2] = temp;
}

int partition(std::vector<int>& list, int lo, int hi) {
    // Choose pivot element
    int pivot = list[floor((hi + lo) / 2.0f)]; // Value in the middle

    int left = lo - 1;
    int right = hi + 1;

    while (true) {
        do { left++; } while (list[left] < pivot);

        do { right--; } while (list[right] > pivot);

        if (left >= right) // Return pivot if crossed
            return right;
        
        swap(list, left, right);
    }
}

void quicksort(std::vector<int>& list, int lo, int hi) {
    if (lo >= 0 && hi >= 0 && lo < hi) {
        int pivot = partition(list, lo, hi);
        quicksort(list, lo, pivot);
        quicksort(list, pivot + 1, hi);
    }
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::vector<int> values{};
    split(values, input);
    
    swap(values, 0, values.size() - 1); // Remove first value (list size) fast
    values.pop_back();

    // Sort list of numbers
    quicksort(values, 0, values.size() - 1);

    // Print sorted list
    for (int i = 0; i < values.size(); i++) {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}