#include <iostream>

using namespace std;

int main()
{
    int array[9]={5, 9, 3, 1, 2, 8, 4, 7, 6};
    int temporary;
    
    for (int i = 1; i < 9; i++) { // loop runs through the end of array
        temporary = array[i]; // puts array with first index, assume its the smallest
        int j = i - 1; 

        while (j >= 0 && array[j] > temporary) { //while loop runs if array[j] is bigger than temporary (not sorted)
            array[j + 1] = array[j];
            j = j - 1;
        } // exits when sorted (specific number of indexes)
        array[j + 1] = temporary; // replace temporary
    }
    
    for (int k = 0; k < 9; k++){
        cout << array[k] << " ";
    }
    return 0;
}
