>>>>>>>>>  TYPEDEF  <<<<<<<<<<

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
