#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {3, 5, 8, 1, 2, 9, 4, 7, 6};
    int n = 8;

    // Initial array
    cout << "Initial Array: ";
    printArray(arr, n);

    // Outer loop for each partitioning
    for (int start = 0; start < n - 1; start++) {
        int pivot = arr[start];

        int count = 0;
        for (int i = start + 1; i < n; i++) {
            if (arr[i] <= pivot)
                count++;
        }

        // Giving pivot element its correct position
        int pivotIndex = start + count;
        swap(arr[pivotIndex], arr[start]);

        // Sorting left and right parts of the pivot element
        int i = start, j = n - 1;
        while (i < pivotIndex && j > pivotIndex) {
            while (arr[i] <= pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i < pivotIndex && j > pivotIndex) {
                swap(arr[i++], arr[j--]);
            }
        }

        // Print array after each partitioning
        cout << "Array after partition " << start + 1 << ": ";
        printArray(arr, n);
    }

    // Final sorted array
    cout << "Final Sorted Array: ";
    printArray(arr, n);

    return 0;
}

