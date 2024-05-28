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

//helper function
void merge(int array[], int leftindex, int midIndex, int rightIndex){
    /*merge sort code for splitting to sub arrays*/
    int leftArraySize = midIndex - leftindex +1;
    int rightArraySize = rightIndex - midIndex;
    
    int leftArray[leftArraySize];
    int rightArray[rightArraySize];
    
    for (int i=0; i<leftArraySize; i++) {
        leftArray[i] = array[leftindex+i];
    }
    for (int j=0; j<rightArraySize; j++) {
        rightArray[j] = array[midIndex+1 + j];
    }
    
    /*merge sort code for combining sub arrays*/
    int i=0;
    int j=0;
    int index = leftindex;
    
    while (i<leftArraySize && j<rightArraySize) {
        if (leftArray[i] <= rightArray[j]) {
            array[index] = leftArray[i];
            index++;
            i++;
        }
        else{
            array[index] = rightArray[j];
            index++;
            j++;
        }
    }
    
    while (i<leftArraySize) {
        array[index] = leftArray[i];
        index++;
        i++;
    }
    
    while (j<rightArraySize) {
        array[index] = rightArray[j];
        index++;
        j++;
    }
}

void mergeSort(int array[], int leftIndex, int rightIndex){
    if(leftIndex >= rightIndex) return;
    
    int midIndex = leftIndex + (rightIndex-leftIndex)/2;
    mergeSort(array, leftIndex, midIndex);
    mergeSort(array, midIndex+1, rightIndex);
    merge(array, leftIndex, midIndex, rightIndex);
}

void swap(int array[], int firstIndex, int lastIndex){
    int temp = array[firstIndex];
    array[firstIndex] = array[lastIndex];
    array[lastIndex] = temp;
}

int pivot(int array[], int pivotIndex, int endIndex){
    int swapIndex = pivotIndex;
    for(int i= pivotIndex + 1; i<=endIndex; i++){
        if (array[swapIndex] < array[i]) {
            swapIndex++;
            swap(array, swapIndex, i);
        }
    }
    swap(array,pivotIndex,swapIndex);
    return swapIndex;
}

int main(int argc, const char * argv[]) {
    int arr1[] = {4,7,9,2,3,1};
    int size = sizeof(arr1)/sizeof(arr1[0]);
    mergeSort(arr1, 0, size-1);
    for(auto value: arr1){
        cout<< value << " ";
    }
}
