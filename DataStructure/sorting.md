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





## Insertion Sort :







## Quick Sort :

