## MISC :



1)  Sizeof('\0')  ----> 4 Bytes // size of int like normal character
    Sizeof(NULL)  ----> 8 Bytes  // size of Pointer



##  OPERATORS :


1) Bitwise operator is not allowed on Float/double values.

2) void main()
    {
        int k =8;
        int m = 7;

        k<m ? k++:m=k;          // Lvalue Error, Assignment is not possible in ternary operator
        
        PF("%d ",k);

    }

## STRUCTURE :

1. Stucture/Union can't have a static member in C.

2. Structure can't have array of bit field.

3) IT is implementation dependent to assign an out of range value to a bit field member.
   but gcc output is as following.....
   
    ```code()
        struct tag
        {
            int i:1;
            int j:2;
            int k:3;
            int l:4;
         };
         
         struct st s;
         s.i =1;
         s.j =2;
         s.k =5;
         s.l =10;
    ```


         + **OUTPUT:**
                    i = -1
                    j = -2
                    k = -3
                    l = -6
    
                 Because MSB will be used as sign bit.
                     -----
                 i = | 1 | = -1
                     -----
                     --------
                 j = | 1 | 0| = -2 // Compiler store negative data in 2's compliment in memory.
                     --------
                     -------------
                 k = | 1 | 0 | 1 | = -3 // 2's compliment
                     -------------
                     -----------------   
                 l = | 1 | 0 | 1 | 0 | = -6 // 2's compilement
                     -----------------   


4) we can't have pointer to bit field members they  may not start at a byte boundry.

5) A special unnammmed bit field of size 0 is used to force alignment on next boundry.

6) Float and double is not allowed for bit field.

## Header files

```markdown
struct tag t;   // it is posssible.

stuct tag
{
    char ch;
    int arr[4];
};

main()
{
    t.ch = 'A';
    t.Arr[0] = 12;

    PF("%c %d\n",t.ch,t.arr[0]);

}

OUTPUT :    NO Error
            A,12
```

8) Two structure can't be compare. Although they are same type.But assignment two structure of same type
   is possible. 

   ```markdown
   struct tag p1 ={1};
   struct tag p2 ={1};
   struct tag p3 = p1; // NO ERROR,all value of p1 will  accomodate into p3.
   
    if(p1 == p2) PF("Equal");   // Compiler Error
    else PF("NOT Equal");
   ```

9. Structure can't be initilize with declaration. Because structure datatype declare no memory
   allocate. Memory allocate when variable are created.

10. Designated initilization of structure allows random initilize of a structure members.

    

    ## Bit Filed : 

    ```markdown
    case 1:                                 
    struct tag{       
     unsigned int a; // First 4 bytes            
     unsigned int b; // second 4 bytes            
     unsigned int c; // thrid 4 bytes            
     };
    
    >>>>>>>   OUTPUT: 12 bytes
    
        case 2:                                 
                struct tag{                        
    
                    unsigned int a:1;  // fisrt 4 bytes         
                    unsigned int b:31; // will  get accomodated in the 1st 4 Bytes         
                    unsigned int c:1;  // Second 4 Bytes are allocate         
    
                };
                
                 >>>>>>> OUTPUT: 8 Bytes
                 
           case 3:                                 
                struct tag{                        
    
                    unsigned int a:1;  // fisrt 4 bytes         
                    unsigned int b:32; // will not get accomodated in the 1st 4 Bytes so 2nd Byte will allocate         
                    unsigned int c:1;  // will not accomodate in Second 4 Bytes So 3rd Byte will allocate         
    
                };
    
            >>>>>>> OUTPUT: 12 Bytes
            
           case 4:                                 
                struct tag{                        
    
                    unsigned int a:1;  // fisrt 4 bytes         
                    unsigned int b:1;  // will  get accomodated in the 1st 4 Bytes         
                    unsigned int c:1;  // will get accomodated int 1st 4 Bytes         
    
                };
    
            >>>>>>> OUTPUT: 4 Bytes
            
                case 5:                                 
                struct tag{                        
    
                    unsigned int a:32;   // fisrt 4 bytes         
                    unsigned int b:1;   // Second 4 Bytes are allocate.         
                    unsigned int c:1;  // will get accomodate in the second 4 bytes.       
    
                };
    
            >>>>>>> OUTPUT: 8 Bytes
            
                case 6: // Special case                                 
                struct tag{                        
    
                    unsigned int a:5;  // fisrt 4 bytes         
                    unsigned int :0;   // will  get accomodated in the 1st Bytes         
                    unsigned int c:8;  // Second 4 Bytes are allocate         
    
                };
    
            >>>>>>> OUTPUT: 8 Bytes
    ```

     
     
     >>>>>>>>  UNION  <<<<<<<<<<

## UNION :









## ENUMS :

1. Only integer constant are allowed into Enums

2) All enum constant must be unique in their sccope.
    
    
        enum{
             a,b,c
            }HI;
                
        enum{
                c,d,e
            }HELLO;
        
        'C' can't be in same file with same scope.
        
        can be declare Enum anywhere in file ? or in any funcaion. search scope means here.??????
    
3. we can't modify the value of Enum constant.
      

    ```markdown
      Enum San{
               a,b,c=5
             };
    
    enum San s;
    
    main(){
            s++;                // No Error
            c++;                // Error can't modify
            printf("%d",c);
          }
    ```

4. There is no physical memory for enum constants only logical memory.



## Typedef :

1) typedef follow scope rule.
2) typedef defined substitutes can not re-defined again.
    i.e
        typedef char a;
        typedef int a;  // Error

3) typedef can not typedef with other term.
    i.e
        typedef typedef TF; // Error

4) we cant use yet to be typedef-ed data type inside while applying typedef itself.
   i.e
        typedef struct node{

            int data;
            NODE *ptr; // ERROR
       
        }NODE;

5) Both cases are Correct and valid in gcc compiler.

   typedef unsigned long ul;
   unsigned long typedef ul;



## Pointers :

```code()
```

1) int main()
   {

    int i;
    int *ptr = (int *)malloc(5*sizeof(int)); // Suppose address is 11000

    for(i=0; i<5; i++)
    {                                    // -----------
        ptr[i] = i;                      // |0|1|2|3|4|
                                         // -----------
    }

    PF("%d ",*ptr++); // o/p : 0         // ( * ( ptr++ ) ), post increment in address.  |0|1|2|3|4|  ->> addr(11001)

    PF("%d ",(*ptr)++); // o/p : 1       // first derefrence and then increment in value. |0|2|2|3|4| ->> addr(11001)

    PF("%d ",*ptr); // o/p : 2          // |0|2|2|3|4| ->> addr(11001)

    PF("%d ",*++ptr); // o/p : 2        // first increment in Address then dereference. |0|2|2|3|4| ->> addr(11002)

    PF("%d ",++*ptr);// o/p : 3         // First derefrence and then increment value.   |0|2|3|3|4| ->> addr(11002)

    PF("%d ",*ptr);

}

OUTPUT :
        0 1 2 2 3

```
```

2) void pointer can't be derefrence. we must typecast before using it.



===========================================================================================================================



## Funcations :

1) Funcation can be decalare inside the funcation but can't define inside the funcation.
    
       
    
    
    
    ```code()
     main()
    
    {
    	void fun();     // No Error
    }
    void fun()
    {
        ------
        ------
    }
    ```
    
2. If we do not mention any reture type of a funcation then by default it is integer.

3. Two return statements should not come successively.

4. a funcation can take 127 arguments in C.

5. sizeof give the value of any funcation will always return type of funcation.

    ```ruby
    int fun(void)
        {
            return ANY_VALUE;
    }
          
    6. sizeof(fun); // output will be size of funcation return type.
    ```
