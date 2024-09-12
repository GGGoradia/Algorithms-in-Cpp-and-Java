#include <iostream>
#include <vector>

int scalarMultiplications = 0;
int scalarAdditions = 0;

void matrixAdd(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
            scalarAdditions++;
        }
    }
}

void matrixMultiply(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C, int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        scalarMultiplications++;
    } else {
        int newSize = size / 2;

        std::vector<int> inner(newSize, 0);
        std::vector<std::vector<int>> 
            A11(newSize, inner), A12(newSize, inner), A21(newSize, inner), A22(newSize, inner),
            B11(newSize, inner), B12(newSize, inner), B21(newSize, inner), B22(newSize, inner),
            C11(newSize, inner), C12(newSize, inner), C21(newSize, inner), C22(newSize, inner),
            M1(newSize, inner), M2(newSize, inner), M3(newSize, inner), M4(newSize, inner), 
            M5(newSize, inner), M6(newSize, inner), M7(newSize, inner);

        // Dividing matrices A and B into 4 sub-matrices each
        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + newSize];
                A21[i][j] = A[i + newSize][j];
                A22[i][j] = A[i + newSize][j + newSize];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + newSize];
                B21[i][j] = B[i + newSize][j];
                B22[i][j] = B[i + newSize][j + newSize];
            }
        }

        // Computing the submatrices of C using recursive multiplication
        matrixMultiply(A11, B11, M1, newSize);
        matrixMultiply(A12, B21, M2, newSize);
        matrixAdd(M1, M2, C11, newSize);

        matrixMultiply(A11, B12, M1, newSize);
        matrixMultiply(A12, B22, M2, newSize);
        matrixAdd(M1, M2, C12, newSize);

        matrixMultiply(A21, B11, M1, newSize);
        matrixMultiply(A22, B21, M2, newSize);
        matrixAdd(M1, M2, C21, newSize);

        matrixMultiply(A21, B12, M1, newSize);
        matrixMultiply(A22, B22, M2, newSize);
        matrixAdd(M1, M2, C22, newSize);

        // Combining the 4 submatrices into a single matrix
        for (int i = 0; i < newSize; i++) {
            for (int j = 0; j < newSize; j++) {
                C[i][j] = C11[i][j];
                C[i][j + newSize] = C12[i][j];
                C[i + newSize][j] = C21[i][j];
                C[i + newSize][j + newSize] = C22[i][j];
            }
        }
    }
}

int main() {
    int n = 4; // Example size (n = 2^2)
    
    std::vector<std::vector<int>> A = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    std::vector<std::vector<int>> B = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };
    
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));

    matrixMultiply(A, B, C, n);

    std::cout << "Product matrix C:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << C[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Total scalar multiplications: " << scalarMultiplications << std::endl;
    std::cout << "Total scalar additions: " << scalarAdditions << std::endl;

    return 0;
}
