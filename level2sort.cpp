#include <iostream>

using namespace std;

int main()
{
    int array[9]={5, 9, 3, 1, 2, 8, 4, 7, 6};
    int minIndex= 0;
    int temporary;
    
    for (int i = 0; i < 9-1; i++){ //loops after inner loop exits (minIndex sorted)
        for(int j = i+1; j < 9; j++){ // runs through end of array 
            if(array[j] < array[minIndex]){ // check minimum number
                minIndex = j; // saves minNumber index = minIndex
            }
        }
        if (minIndex != i){ // if condition check if minIndex is not equal to current index : i 
            temporary = array[i]; // park
            array[i] = array[minIndex]; // swap
            array[minIndex] = temporary; //swap
        }
    }
    
    for (int k = 0; k < 9; k++){
        cout << array[k] << " ";
    }
    
    return 0;
}
