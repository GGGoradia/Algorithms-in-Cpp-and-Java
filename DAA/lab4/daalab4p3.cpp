#include <iostream>
#include <vector>
#include <algorithm>

// Merge function for the odd-indexed elements
void merge(std::vector<int>& A, std::vector<int>& oddElements, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (oddElements[i] <= oddElements[j]) {
            A[2 * k + 1] = oddElements[i];
            i++;
        } else {
            A[2 * k + 1] = oddElements[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        A[2 * k + 1] = oddElements[i];
        i++;
        k++;
    }

    while (j <= right) {
        A[2 * k + 1] = oddElements[j];
        j++;
        k++;
    }
}

// Recursive function to sort the odd-indexed elements using merge sort
void sortOddIndices(std::vector<int>& A, std::vector<int>& oddElements, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort the left half
        sortOddIndices(A, oddElements, left, mid);

        // Sort the right half
        sortOddIndices(A, oddElements, mid + 1, right);

        // Merge the two halves
        merge(A, oddElements, left, mid, right);
    }
}

// Function to extract odd-indexed elements, sort them, and place them back
void sortArrayOddIndices(std::vector<int>& A) {
    int n = A.size();
    int oddCount = n / 2;

    std::vector<int> oddElements(oddCount);
    for (int i = 0; i < oddCount; i++) {
        oddElements[i] = A[2 * i + 1];
    }

    // Sort odd-indexed elements
    sortOddIndices(A, oddElements, 0, oddCount - 1);
}

int main() {
    std::vector<int> A = {-1, 2, -2, -5, 4, 0};

    sortArrayOddIndices(A);

    std::cout << "Sorted array with odd indices sorted: " << std::endl;
    for (int i = 0; i < A.size(); i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
