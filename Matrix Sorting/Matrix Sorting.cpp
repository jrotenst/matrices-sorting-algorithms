#include <iostream>

using namespace std;

void displayMatrix(int matrix[][10], int size);
void fillMatrix(int matrix[][10], int size);
void bubbleSort(int** matrix, int size);
void insertionSort(int** matrix, int size);
void selectionSort(int** matrix, int size);

int main()
{
    const int size = 10;
    int matrix[size][size];

    fillMatrix(matrix, size);
    cout << endl;
    displayMatrix(matrix, size);
}

void fillMatrix(int matrix[][10], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = i * j;
            cout << matrix[i][j] << ", ";   // display value added
        }
        cout << endl;
    }
}

void displayMatrix(int matrix[][10], int size) {
    for (int i = 0; i < size * size; i++) {

        if (i % size == 0) {
            cout << endl;
        }
        cout << *(*(matrix) + i) << ", ";
    }
}

void bubbleSort(int** matrix, int size) {

}

void insertionSort(int** matrix, int size) {


}

void selectionSort(int** matrix, int size) {

}

