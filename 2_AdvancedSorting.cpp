#include <iostream>
#include <vector>

// O(nlogn) time complexity
void mergeSort(std::vector<int>&);

int main() {
    int input;
    std::vector<int> arr;
    
    // eg. 5 6 7 1 2 3 4 5 q
    std::cout<<"Enter the integers to sort (enter a non-integer to end) - ";
    while (std::cin >> input) {
        arr.push_back(input);
    }

    mergeSort(arr);
    std::cout<<std::endl<<"The sorted array is - ";
    for (auto& i : arr) {
        std::cout<<i<<" ";
    }

    return 0;
}

void mergeSort(std::vector<int>& arr) {
    if (arr.size() < 2) {
        return;
    }

    std::vector<int> left;
    std::vector<int> right;
    for (int i = 0; i < arr.size() / 2; i ++) {
        left.push_back(arr[i]);
    }
    for (int i = arr.size() / 2; i < arr.size(); i++) {
        right.push_back(arr[i]);
    }
    mergeSort(left);
    mergeSort(right);
    
    int i = 0, j = 0, k = 0;
    while ((i < left.size()) && (j < right.size())) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            ++i;
        }
        else {
            arr[k] = right[j];
            ++j;
        }
        ++k;
    }
    while (i < left.size()) {
        arr[k] = left[i];
        ++i;
        ++k;
    }
    while (j < right.size()) {
        arr[k] = right[j];
        ++j;
        ++k;
    }

    return;
}