#include <iostream>

#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::nanoseconds;

using namespace std;

const int SIZE = 10;
int matrix[SIZE][SIZE];

void displayMatrix(int matrix[][SIZE]);
void loadMatrix(int matrix[][SIZE]);
void bubbleSort(int matrix[][SIZE]);
void insertionSort(int matrix[][SIZE]);
void selectionSort(int matrix[][SIZE]);
void swap(int* val1, int* val2);

template <typename Func>long
long TimeFunc(Func f);


int main()
{
    
    cout << "Loaded matrix:" << endl << endl;
    loadMatrix(matrix);
    displayMatrix(matrix);

    cout << "Bubble sort:" << endl << endl;
    long bubbleSortTime = TimeFunc(bubbleSort);
    displayMatrix(matrix);

    cout << "Reloaded matrix:" << endl << endl;
    loadMatrix(matrix);
    displayMatrix(matrix);

    cout << "Insertion sort:" << endl << endl;
    long insertionSortTime = TimeFunc(insertionSort);    
    displayMatrix(matrix);

    cout << "Reloaded matrix:" << endl << endl;
    loadMatrix(matrix);
    displayMatrix(matrix);

    cout << "Selection sort:" << endl << endl;
    long selectionSortTime = TimeFunc(selectionSort);
    displayMatrix(matrix);

    cout << endl << "SORT TIMES" << endl << endl;
    cout << "Bubble Sort: " << bubbleSortTime << endl;
    cout << "Insertion Sort: " << insertionSortTime << endl;
    cout << "Selection Sort: " << selectionSortTime << endl;

}

void loadMatrix(int matrix[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = i * j;
        }
    }
}

void displayMatrix(int matrix[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

void bubbleSort(int matrix[][SIZE]) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < SIZE * SIZE; i++) {                     
            if (*(*matrix + i - 1) > *(*matrix + i)) {                                   
                swap(*matrix + i - 1, *matrix + i);
                swapped = true;
            }
        }
    } while (swapped);
}

void insertionSort(int matrix[][SIZE]) {
    int current, j;
    for (int i = 1; i < SIZE * SIZE; i++) {
        current = *(*matrix + i);
        j = i - 1;

        while (j >= 0 && *(*matrix + j) > current) {
            *(*matrix + j + 1) = *(*matrix + j);
            j--;
        }
        *(*matrix + j + 1) = current;
    }
}

void selectionSort(int matrix[][SIZE]) {
    int min, i, j;
    for (i = 0; i < SIZE * SIZE; i++) {
        min = i;

        for (j = i + 1; j < SIZE * SIZE; j++) {
            if (*(*matrix + j) < *(*matrix + min)) {
                min = j;
            }
        }
        swap(*matrix + min, *matrix + i);
    }
}

void swap(int* val1, int* val2) {
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

template <typename Func>long
long TimeFunc(Func f) {
    auto begin = steady_clock::now();
    f(matrix);
    auto end = steady_clock::now();
    return duration_cast<nanoseconds>(end - begin).count();
}



