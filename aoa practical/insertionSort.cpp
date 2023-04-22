#include<iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int size){
    int i,j,key;

    for(int i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

int main(){
     
    int size;
    cout << "Enter size of array : ";
    cin >> size;
    int arr[size];
    cout << "Enter array elements : ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    insertionSort(arr,size);
    cout << "Sorted array :  ";
    printArray(arr, size);
    

    return 0;
}