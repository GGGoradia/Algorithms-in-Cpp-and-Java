#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; ++j) {
        if (arr[j] < pivot) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[right]);
    return i;
}

int quickSelect(std::vector<int>& arr, int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }

    int pivotIndex = partition(arr, left, right);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickSelect(arr, left, pivotIndex - 1, k);
    } else {
        return quickSelect(arr, pivotIndex + 1, right, k);
    }
}

int findKthSmallest(std::vector<int>& arr, int k) {
    return quickSelect(arr, 0, arr.size() - 1, k - 1);
}

int main() {
    std::vector<int> arr = {1, 7, 8, 4, 3};
    int k = 4;
    int result = findKthSmallest(arr, k);
    std::cout << "The " << k << "th smallest element is " << result << std::endl;
    return 0;
}
