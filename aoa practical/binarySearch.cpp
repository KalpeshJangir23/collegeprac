#include <iostream>
using namespace std;


int binarySearch(int arr[], int size, int target){
    int start = 0;
    int end = size - 1;

    while(end >= start){
        int mid = start + (end - start)/2;

        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}

// void sort(int arr[], int size){
//     for(int i = 0; i < size - 1; i++){
//         for(int j = 0; j < size - i; j++){
//             if(arr[j] > arr[j+1]){
//                 swap(&arr[j], &arr[j+1]);
//             }
//         }
//     }
// }

// void swap(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

int main(){

    int size, target;
    cout << "Enter size of array : ";
    cin >> size;
    int arr[size];
    cout << "Enter array elements : ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    // sort(arr,size);
    
    cout << "Enter Target element : ";
    cin >> target;

    int index = binarySearch(arr,size,target);

    cout << index;
    
    return 0;
}