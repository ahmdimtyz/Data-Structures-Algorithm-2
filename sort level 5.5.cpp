#include <iostream>
#include <algorithm>

using namespace std;

// Partition function for quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the pivot (can be randomized for better performance)

    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quicksort function
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array into two segments
        int pi = partition(arr, low, high);

        // Recursively sort the two segments
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {8, 3 ,2, 9, 7,1, 5,4};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

