// Time complexity : O(N^2)
// Space complexity : O(N)

#include <iostream>
using namespace std;





void selectioSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{

    int size;
    cout << "Enter size of array : ";
    cin >> size;
    int arr[size];
    cout << "Enter array elements : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    selectioSort(arr, size);
    cout << "Sorted array :  ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}