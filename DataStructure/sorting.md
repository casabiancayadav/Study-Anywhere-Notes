# Sorting :





## Selection Sort :

* Less number of swaps.

* Selection sort intermediate results are useful. Each pass gives shortest result.

* NOT adaptive and Stable.

```c
voidSelectionSort (int *arr, intsize )
{
inti , j, k;

for(i=0; i< size -1; i++ )
  {
for(  j = k = i; j < size; j++ )
      {
if( arr[ j ] <arr [ k ] )
           {
              k = j;
           }     
      }//for(j)
swap( &arr[ i ], &arr[ k ]);
   }//for( i )

} //SelectionSort( )

```





## Bubble Sort :

```cpp
//Bubble Sorting
int swap(int *a, int *b){
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

int * bubbleSorting(int *arr){
    int size = sizeof(arr)/sizeof(arr[0]);
    int max;
    for(int i=0; i < size-1; ++i){   
        for(int j=0; j < size-1; ++j){
            if(arr[j] > arr[j+1]){
                swap( &arr[j], &arr[j+1]);
            }
        }
    }   
    return arr;
}


```

```ruby
/* Explanations about bubble sorting. 
	-->arr = [1,4,2,9,5]
	
	at i=0,j=0, =>> [1,4,2,9,5] , No swap
    				^ ^
	at i=0,j=1, =>> [1,4,2,9,5] , Yes swap [1,2,4,9,5] 
    				  ^ ^   				
	at i=0,j=2, =>> [1,2,4,9,5] , No swap 
    				    ^ ^   				
	at i=0,j=3, =>> [1,2,4,9,5] , Yes swap [1,2,4,5,9] 
       				      ^ ^   				
    Now one iteration of J loop has finished. 
    So One element has reached at it best position.
*/
```



* After Complete each iteration of J loop we must get maximum number at last OR at its best position.
* If there are not any swap it means all elements are already at its best position.



## Insertion Sort :







## Quick Sort :

