#include <iostream>

using namespace std;

void merge(int a[], int low, int mid, int high) {
  int i = low, j = mid + 1, index = low, temp[8], k;

  while ((i <= mid) && (j <= high)) {
    if (a[i] < a[j]) {
      temp[index] = a[i];
      i++;
    } else {
      temp[index] = a[j];
      j++;
    }
    index++;
  }

  if (i > mid) {
    while (j <= high) {
      temp[index] = a[j];
      j++;
      index++;
    }
  } else 
  {
    while (i <= mid) {
      temp[index] = a[i];
      i++;
      index++;
    }
  }

  for (k = low; k < index; k++) 
  {
    a[k] = temp[k];
  }

}

void mergesort(int a[], int low, int high) {
  if (low < high) {
    int middle = (low + high) / 2; 

    mergesort(a, low, middle); 
    mergesort(a, middle + 1, high); 

    merge(a, low, middle, high); 
  }
  
  for (int i = 0; i < 8; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main() {
  int a[] = {8, 3 ,2, 9, 7,1, 5,4};
  mergesort(a, 0, 7);

  for (int i = 0; i < 8; i++) {
    cout << a[i] << " ";
  }
  
  return 0;
}