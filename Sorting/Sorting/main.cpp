//
//  main.cpp
//  Sorting
//
//  Created by Rohan Soni on 26/5/2024.
//

#include <iostream>
using namespace std;

void bubbleSort(int array[],int size){
    for (int i = size-1; i>0 ; i--) {
        for (int j = 0; j < i; j++) {
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int arr1[] = {4,7,9,2,3,1};
    int size = sizeof(arr1)/sizeof(arr1[0]);
    bubbleSort(arr1, size);
    for(auto value: arr1){
        cout<< value << " ";
    }
}
