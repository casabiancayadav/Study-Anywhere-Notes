:notebook: Errors/Bugs =  More Code

​		:bow_and_arrow: E = MC<sup>2</sup>



:question:  ***How to Find mid value into Binary Search ?***

 :a: It is very important to find mid value. It is very easy to do it.

```c 
int mid = ( first + end )/2 ;

This works fine for small interger values. But fails when integer value become high. It gives runtime error of overflow.
```

```c
int mid = ( first + ( (end -first )/2 ) ) ;

This approch is widely used in comptetive programming. It overcomes above problem. 
```

:+1:



:question: **Avoiding use of strlen():**

:a:  

```c
//  Use of strlen() can be avoided by:
for (i=0; s[i]; i++) 
{ 
}
// loop breaks when the character array ends.
```



:question:  **Maximum size of the array:** We must be knowing that the maximum size of array declared inside the main function is of the order of 10^6 but if you declare array globally then you can declare its size upto 10^7.

 :question: **Calculating the number of digits directly:** 

:a: To calculate number of digits in a number, instead of looping you can efficiently use log :

```c
Number of digits in N =floor(log10(N)) + 1;  
```



:question:  **Checking if the number is even or odd without using the % operator:**

:a:  

```cpp
if (num & 1)
cout << "ODD";
else
cout << "EVEN";

```



:question:  **Swapping of 2 numbers using XOR:**

:a: This method is fast and doesn’t require the use of 3rd variable.

```cpp
// A quick way to swap a and b
a ^= b;
b ^= a;
a ^= b;
```



:question:  **[Efficient trick to know if a number is a power of 2](https://www.geeksforgeeks.org/program-to-find-whether-a-no-is-power-of-two/)** 

:a: the normal technique of division the complexity comes out to be O(logN), but it can be solved using O(v) where v are the number of digits of number in binary form.

```cpp
/* Function to check if x is power of 2*/
bool isPowerOfTwo (int x)
{
/* First x in the below expression is
	for the case when x is 0 */
return x && (!(x&(x-1)));
}
```





:question: **Print a binary representation of a number**

If you want to print, say, last 20 bits of a number, it's not necessary to write something like.

```
void show_binary(int n) {
    for (int i = 0; i < 20; ++i) {
        cout << !!(n & (1 << i));
    }
    cout << "\n";
}
```

Instead, one can simply write

```
cout << bitset<20>(n) << "\n";
```



:bow_and_arrow:  if you want to print an octal or a hexadecimal representation of a number, you can simply write `cout << oct << n << "\n"` and `cout << hex << n << "\n"`, respectively.



:question: **Introducing variables inside an if statement**

:a: Imagine the following: you have a function `f()`, which takes time to be computed, and if its value satisfies some condition, you want to somehow use it. You don't want to write.

```ruby
if (is_good(f())) {
    use_somehow(f());
}
```

* since it costs two calls of `f`. You may write something like this:

  ``` cpp
  int x = f();
  if (is_good(x)) {
      use_somehow(x);
  }
  ```



* but this is not very clean and leaves a variable which is not used then, maybe under a potentially useful name. To avoid this, one can wrap all this into a block like this:

  ```cpp
  {
      int x = f();
      if (is_good(x)) {
          use_somehow(x);
      }
  }
  ```

  

* but a shorter version would do the following:

  ```cpp
  if (int x = f(); is_good(x)) {
      use_somehow(x);
  }
  
  This is possible since C++17.
  ```

  

