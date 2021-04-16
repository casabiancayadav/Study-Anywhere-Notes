/*

*/


#include <iostream>
using namespace std;


void isUnique(int *arr, int size)
{
    if(size == 0) return;
    bool flag = 0;

    for(int i=0; i < size; i++)
    {
        for(int j=i+1; j < size; j++)
        {
            if( ( arr[i] == arr[j] ) || flag )
            {
                arr[i] = arr[j];
                flag = 1;
                cout << arr[j] << ", ";
            }
        }
        flag = 0;
    }
for(int i = 0;  i < size; i++) cout << arr[i] << ", ";
}

int main()
{
    int arr[] = {4,1,5,6,4,2,1,7,6,5}; // {4,1,5,6,2,7}
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "Hello World \n"; 
    
    isUnique( arr, size);

    for(int i = 0;  i < size; i++) cout << arr[i] << ", ";

    return 0;
}