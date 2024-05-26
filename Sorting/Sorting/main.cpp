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

void selectionSort(int array[], int size){
    for(int i = 0; i < size; i++){
        int minIndex = i;
        for (int j = i+1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if(i != minIndex){
            int temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }
    }
}

void insertionSort(int array[], int size){
    for(int i=1; i<size;i++){
        int temp = array[i];
        int j = i-1;
        while (j>-1 && temp < array[j]) {
            array[j+1] = array[j];
            array[j] = temp;
            j--;
        }
    }
}

int main(int argc, const char * argv[]) {
    int arr1[] = {4,7,9,2,3,1};
    int size = sizeof(arr1)/sizeof(arr1[0]);
    insertionSort(arr1, size);
    for(auto value: arr1){
        cout<< value << " ";
    }
}
