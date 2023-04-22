//Time Complexity O(n^2) 
//best case O(n)

#include<iostream>
using namespace std;


void insertionSort(int arr[], int size){
    for(int i = 0; i <= size-1; i++){
        int  j =i;
        while (j>0 && arr[j-1]>arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
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
  
      for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    

    return 0;
}