#include <iostream>
using namespace std;

// Sparse Matrix Representation
struct SparseMatrix {
    int row;
    int col;
    int value;
};

// Function to convert a standard 2D matrix to a sparse matrix representation
void convertToSparse(int matrix[][4], int rows, int cols, SparseMatrix sparse[], int &nonZeroCount) {
    nonZeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[nonZeroCount].row = i;
                sparse[nonZeroCount].col = j;
                sparse[nonZeroCount].value = matrix[i][j];
                nonZeroCount++;
            }
        }
    }
}

// Function to print the sparse matrix representation
void printSparseMatrix(SparseMatrix sparse[], int nonZeroCount) {
    cout << "Sparse Matrix Representation:" << endl;
    cout << "Row\tColumn\tValue" << endl;
    for (int i = 0; i < nonZeroCount; i++) {
        cout << sparse[i].row << "\t" << sparse[i].col << "\t" << sparse[i].value << endl;
    }
}

int main() {
    // Example 2D matrix (4x4)
    int matrix[4][4] = {
        {5, 0, 0, 0},
        {0, 8, 0, 0},
        {0, 0, 3, 0},
        {0, 6, 0, 0}
    };

    // Sparse matrix representation (maximum size is rows * cols)
    SparseMatrix sparse[16];
    int nonZeroCount;

    // Convert to sparse matrix
    convertToSparse(matrix, 4, 4, sparse, nonZeroCount);

    // Print the sparse matrix
    printSparseMatrix(sparse, nonZeroCount);

    return 0;
}
