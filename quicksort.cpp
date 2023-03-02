#include <iostream>

void swap(int list[], int index1, int index2) {
    int temp = list[index1];
    list[index1] = list[index2];
    list[index2] = temp;
}

void insertionSort(int list[], int lo, int hi) {
    // for (int i = lo + 1; i <= hi; i++) { // "Faster" version??
    //     int x = list[i];
    //     int j = i - 1;
    //     while (j >= 0 && list[j] > x) {
    //         list[j + 1] = list[j];
    //         j--;
    //     }
    //     list[j + 1] = x;
    // }
    for (int i = lo + 1; i <= hi; i++)
        for (int j = i; j > 0 && list[j-1] > list[j]; j--)
            swap(list, j, j - 1);
}

int medianOf3(int a, int b, int c) {
    if ((a > b) ^ (a > c))
        return a;
    else if ((b < a) ^ (b < c))
        return b;
    else
        return c;
}

int ninther(int list[], int lo, int hi) {
    int third = int((hi - lo) / 3.0f);
    return medianOf3(
        medianOf3(list[lo], list[int((lo + third) / 2.0f)], list[lo + third]), // First third
        medianOf3(list[lo + third + 1], list[lo + int((third + 1 + 2 * third) / 2.0f)], list[lo + 2 * third]), // Middle third
        medianOf3(list[lo + 2 * third + 1], list[int((2 * third + 1 + hi) / 2.0f)], list[hi]) // Last third
    );
}

int partition(int list[], int lo, int hi) {
    // Choose pivot element
    int pivot = list[int((hi + lo) / 2.0f)]; // Value in the middle
    // int pivot = medianOf3(list[lo], list[floor((hi + lo) / 2.0f)], list[hi]);
    // int pivot = ninther(list, lo, hi);

    int left = lo - 1;
    int right = hi + 1;

    while (true) {
        while (list[++left] < pivot);

        while (list[--right] > pivot);

        if (left >= right) // Return pivot if crossed
            return right;
        
        swap(list, left, right);
    }
}

void quicksort(int list[], int lo, int hi) {
    if (hi - lo < 32) {
        insertionSort(list, lo, hi);
    } else if (lo >= 0 && hi >= 0 && lo < hi) {
        int pivot = partition(list, lo, hi);
        quicksort(list, lo, pivot);
        quicksort(list, pivot + 1, hi);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int length;
    std::cin >> length;
    
    int* values = new int[length];

    int i = 0;
    int value;
    while (std::cin >> value)
        values[i++] = value;

    // Sort list of numbers
    quicksort(values, 0, length - 1);

    // Print sorted list
    for (int i = 0; i < length; i++) {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}