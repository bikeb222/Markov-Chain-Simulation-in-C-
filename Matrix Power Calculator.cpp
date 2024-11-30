#include <iostream>
#include <iomanip> 

using namespace std;
const int MAX_SIZE = 10; 

void printMatrix(double matrix[MAX_SIZE][MAX_SIZE], int size) {
    cout << fixed << setprecision(4); 
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void matrixMultiply(double A[MAX_SIZE][MAX_SIZE], double B[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE], int size, int step) {
    double temp[MAX_SIZE][MAX_SIZE] = { 0 };   
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp[i][j] = 0; 
            for (int k = 0; k < size; ++k) {
                temp[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = temp[i][j];
        }
    }
    cout << "Matrix after multiplication step " << step << ":" << endl;
    printMatrix(result, size);
}

void matrixPower(double matrix[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE], int size, int n) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
    cout << "Original matrix:" << endl;
    printMatrix(matrix, size);
    int step = 1; 
    double temp[MAX_SIZE][MAX_SIZE]; 
    matrixMultiply(matrix, matrix, temp, size, step++); 
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = temp[i][j];
        }
    }
    while (n-1 > 0) {
            matrixMultiply(result, matrix, temp, size, step++); 
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    result[i][j] = temp[i][j];
                }
            }       
        n -= 1;
    }
}

int main() {
    int size, exponent;
    double matrix[MAX_SIZE][MAX_SIZE];
    double result[MAX_SIZE][MAX_SIZE];
    cout << "Enter the dimension of the square matrix: ";
    cin >> size;

    if (size > MAX_SIZE) {
        cerr << "Matrix size exceeds limit! Please adjust the MAX_SIZE constant." << endl;
        return 1;
    }
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << "Enter the exponent: ";
    cin >> exponent;
    matrixPower(matrix, result, size, exponent);
    cout << "The matrix raised to the power of " << exponent << " is:" << endl;
    printMatrix(result, size);
    return 0;
}
