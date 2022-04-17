#include <bits/stdc++.h>
#include <stdio.h>

int size = 0;
void swap(int *a, int *b){
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(int array[], int size, int i){
  if (size == 1){
    printf("Single element in the heap");
  }

  else{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}

void insert(int array[], int newNum){

  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;

    for (int i = size / 2 - 1; i >= 0; i--){
      heapify(array, size, i);
    }

  }
}

void printArray(int array[], int size){

  for (int i = 0; i < size; ++i){
    printf("%d ", array[i]);
  }
  printf("\n");
}

void heapify_2(int arr[], int n, int i) {
    
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify_2(arr, n, largest);
    }
  }
  
  void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
      heapify_2(arr, n, i);
  
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      heapify_2(arr, i, 0);
    }
  }

int main(){

    int array[10];

    insert(array, 23);
    insert(array, 14);
    insert(array, 19);
    insert(array, 55);
    insert(array, 29);
    insert(array, 3);
    insert(array, 56);
    insert(array, 51);
    insert(array, 93);

    printArray(array, size);

    int arr[] = {23,14,19,55,29,3,56,51,93};
    int n = sizeof(arr) / sizeof(arr[0]);
  
    heapSort(arr, n);
  
    printf("Sorted array is : ");
    printArray(arr, n);

}
