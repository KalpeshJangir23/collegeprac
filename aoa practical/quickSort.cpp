#include <iostream>
using namespace std;


int  partition(int arr[], int s, int e){
    int pivot = arr[s];

    int count = 0;
    for(int i = s+1; i <= e; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    
    int pivotIndex = s + count; 
    // swapping pivot & arr[count]
    swap(arr[pivotIndex],arr[s]);

    int i = s;
    int j = e;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivotIndex){
            i++;
        }

        while(arr[j] > pivotIndex){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
       
    }
    return pivotIndex;
    
}

void quickSort(int arr[], int s, int e){
    // base case
    if(s >= e){
        return;
    }
    // partitioning the array in 2 parts
    int p = partition(arr,s,e);

    // call quickSort for left side
    quickSort(arr,s,p-1);

    // call quickSort for right side
    quickSort(arr,p+1,e);
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

    quickSort(arr,0,size-1);
    cout << "Sorted array :  ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

