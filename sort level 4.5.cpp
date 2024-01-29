#include <iostream>

using namespace std;

void merge(int a[], int low, int mid1, int mid2, int high) {
  int i = low, j = mid1 + 1, k = mid2 + 1, index = low, temp[8], l;

  while ((i <= mid1) && (j <= mid2) && (k <= high)) {
    if (a[i] < a[j]) {
      if (a[i] < a[k]) {
        temp[index] = a[i];
        i++;
      } else {
        temp[index] = a[k];
        k++;
      }
    } else {
      if (a[j] < a[k]) {
        temp[index] = a[j];
        j++;
      } else {
        temp[index] = a[k];
        k++;
      }
    }
    index++;
  }

  while ((i <= mid1) && (j <= mid2)) {
    if (a[i] < a[j]) {
      temp[index] = a[i];
      i++;
    } else {
      temp[index] = a[j];
      j++;
    }
    index++;
  }

  while ((j <= mid2) && (k <= high)) {
    if (a[j] < a[k]) {
      temp[index] = a[j];
      j++;
    } else {
      temp[index] = a[k];
      k++;
    }
    index++;
  }

  while ((i <= mid1) && (k <= high)) {
    if (a[i] < a[k]) {
      temp[index] = a[i];
      i++;
    } else {
      temp[index] = a[k];
      k++;
    }
    index++;
  }

  while (i <= mid1) {
    temp[index] = a[i];
    i++;
    index++;
  }

  while (j <= mid2) {
    temp[index] = a[j];
    j++;
    index++;
  }

  while (k <= high) {
    temp[index] = a[k];
    k++;
    index++;
  }

  for (l = low; l < index; l++) {
    a[l] = temp[l];
  }
}

void mergesort3way(int a[], int low, int high) {
  if (low < high) {
    int mid1 = low + (high - low) / 3;
    int mid2 = low + 2 * (high - low) / 3;

    mergesort3way(a, low, mid1);
    mergesort3way(a, mid1 + 1, mid2);
    mergesort3way(a, mid2 + 1, high);

    merge(a, low, mid1, mid2, high);
  }
}

int main() {
  int a[] = {8, 3, 2, 9, 7, 1, 5, 4};
  int size = sizeof(a) / sizeof(a[0]);

  mergesort3way(a, 0, size - 1);

  cout << "After 3-way merge sort: ";
  for (int i = 0; i < size; i++) {
    cout << a[i] << " ";
  }

  return 0;
}
