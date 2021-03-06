# SELF LEARNING

 Q: When do we use Initializer List in C++? 
      Hint: [Search on GEEKSFORGEEKS]



##  CONSTRUCTOR



```markdown

>>>>>>>>    CONSTRUCTOR     <<<<<<<<<

1)  In C++, if we do not write our own, then compiler automatically creates a default constructor,
                                                                           -----------------------             
    a copy constructor and a assignment operator for every class.
    ------------------      ---------------------

2)  Unlike new, malloc() doesn't call constructor.If we replace malloc() with new, the constructor is called, 

    #include<iostream>
    #include<stdlib.h>
    using namespace std;
     
    class Test
    {
    public:
       Test()
       { cout << "Constructor called"; }
    };
     
    int main()
    {
        Test *t = (Test *) malloc(sizeof(Test)); // it will not call constructor.
        Test *s = new Test; // it will call constructor.
        return 0;
    }

3)  #include<iostream>
    #include<string.h>
    using namespace std;
     
    class String
    {
        char *str;
    public:
         String(const char *s);
         void change(int index, char c) { str[index] = c; }
         char *get() { return str; }
    };
     
    String::String(const char *s)
    {
        int l = strlen(s);
        str = new char[l+1];
        strcpy(str, s);
    }
     
    int main()
    {
       String s1("geeksQuiz");
       String s2 = s1;
       s1.change(0, 'G');
       cout << s1.get() << " ";
       cout << s2.get();
    }

output:
    GeeksQuiz GeeksQuiz

 Since there is no copy constructor, the compiler creates a copy constructor.
 The compiler created copy constructor does shallow copy in line " String s2 = s1;"
                                            ----------------------------------------
 So str pointers of both s1 and s2 point to the same location. There must be a user
 -------------------------------------------------------------
 defined copy constructor in classes with pointers ot dynamic memory allocation.
```

4)  #include<iostream>
using namespace std;

class Test
{
public:
  Test();
};

Test::Test()  {
    cout << " Constructor Called. ";
}

void fun() {
  static Test t1;
}

int main() {
    cout << " Before fun() called. ";
    fun();
    fun();
    cout << " After fun() called. ";  
    return 0;
}


ioutput:

Before fun() called. Constructor Called. After fun() called.
Note that t is static in fun(), so constructor is called only once.








====================================================================================================
Q:1

    #include <iostream> 
    using namespace std; 
      
    class Fraction 
    { 
    private: 
        int den; 
        int num; 
    public: 
       void print() { cout << num << "/" << den; } 
       Fraction() { num = 1; den = 1; } 
       int &Den() { return den; } 
       int &Num() { return num; } 
    }; 
      
    int main() 
    { 
       Fraction f1; 
       f1.Num() = 7; 
       f1.Den() = 9; 
       f1.print(); 
       return 0; 
    } 
    
    Solution:
        
    Output: 7/9
The methods Num() and Den() return references to num and den respectively. Since references are returned,
the returned values can be uses as an lvalue, and the private members den and num are modified. The program
compiles and runs fine, but this kind of class design is strongly discouraged (See this). Returning reference

to private variable allows users of the class to change private data directly which defeats the purpose of encapsulation.

Q-2:

#include<iostream> 
using namespace std; 

/* local variable is same as a member's name */
class Test 
{ 
private: 
    int x; 
public: 
    void setX (int x) { Test::x = x; } 
    void print() { cout << "x = " << x << endl; } 
}; 

int main() 
{ 
    Test obj; 
    int x = 40; 
    obj.setX(x); 
    obj.print(); 
    return 0; 
} 

Output: 
x = 40
Scope resolution operator can always be used to access a class member when it is made hidden by local variables.

So the line ???Test::x = x??? is same as ???this->x = x???

>>>> Always remember that copy constructor have constant keyword in his arguments. which we generally forget.

>>>> In general, it is a good idea to use Initializer List to initialize all members of a class,
     because it saves one extra assignment of members. See point 6 of this post for more details.

Q-3:

#include <iostream> 
using namespace std; 

class A 
{ 
	int id; 
public: 
	A (int i) { id = i; } 
	void print () { cout << id << endl; } 
}; 

int main() 
{ 
	A a[2];
	a[0].print(); 
	a[1].print(); 
	return 0; 
} 


There is a compilation error in line ???A a[2]???. There is no default constructor in class A. When we write our own 
parameterzied constructor or copy constructor, compiler doesn???t create the default constructor (See this Gfact).
We can fix the error, either by creating a default constructor in class A, or by using the following syntax to
initialize array member using parameterzied constructor. 

// Initialize a[0] with value 10 and a[1] with 20 
 A a[2] = { A(10),  A(20) } 

 OR simply

 int main()
 {
     A a(10);
     a.print();
     return 0;

}


#include<iostream> 
using namespace std; 

class base 
{ 
public: 
	virtual void show() { cout<<" In Base \n"; } 
}; 

class derived: public base 
{ 
	int x; 
public: 
	void show() { cout<<"In derived \n"; } 
	derived() { x = 10; } 
	int getX() const { return x;} 
}; 

int main() 
{ 
	derived d; 
	base *bp = &d; 
	bp->show(); 
	cout << bp->getX(); 
	return 0; 
} 


Output: Compiler Error: ???class base??? has no member named ???getX???
In the above program, there is pointer ???bp??? of type ???base??? which points to an object of type derived. The call of show() 
through ???bp??? is fine because ???show()??? is present in base class. In fact, it calls the derived class ???show()??? because ???show()???
is virtual in base class. But the call to ???getX()??? is invalid, because getX() is not present in base class. When a base class
pointer points to a derived class object, it can access only those methods of derived class which are present in base class and are virtual.

----------------------------------------------------------------------------------------------------------------------------------------------------


#include<iostream> 
using namespace std; 

class Test 
{ 
	int value; 
public: 
	Test(int v = 0) { value = v; } 
	int getValue() { return value; } 
}; 

int main() 
{ 
	const Test t; 
	cout << t.getValue(); 
	return 0; 
} 


Output: Compiler Error
    In the above program, object ???t??? is declared as a const object. A const object can only call const functions.

To fix the error, we must make getValue() a const function.

#include<iostream> 
using namespace std; 

class Base  
{ 
public: 
    int fun()      { cout << "Base::fun() called"; } 
    int fun(int i) { cout << "Base::fun(int i) called"; } 
}; 

class Derived: public Base  
{ 
public: 
    int fun(char x)   { cout << "Derived::fun(char ) called"; } 
}; 

int main()  
{ 
    Derived d; 
    d.fun(); 
    return 0; 
} 


Output: Compiler Error.
In the above program, fun() of base class is not accessible in the derived class. If a derived class creates a member 
method with name same as one of the methods in base class, then all the base class methods with this name become hidden in derived class 

--------------------------------------------------------------------------------------------------------------------

#include<iostream> 
using namespace std; 
class Base 
{ 
protected: 
	int x; 
public: 
	Base (int i){ x = i;} 
}; 

class Derived : public Base 
{ 
public: 
	Derived (int i):x(i) { } 
	void print() { cout << x ; } 
}; 

int main() 
{ 
	Derived d(10); 
	d.print(); 
} 

Output: Compiler Error
In the above program, x is protected, so it is accessible in derived class. Derived class constructor tries to use 
initializer list to directly initialize x, which is not allowed even if x is accessible. The members of base class 
can only be initialized through a constructor call of base class. Following is the corrected program. 

#include<iostream> 
using namespace std; 
class Base { 
   protected: 
      int x; 
   public: 
      Base (int i){ x = i;} 
}; 

class Derived : public Base { 
   public: 
      Derived (int i):Base(i) { } 
      void print() { cout << x; } 
}; 

int main() 
{ 
    Derived d(10); 
    d.print(); 
} 

Output: 
 10 

-----------------------------------------------------------------------------------------------------------------------------
#include <iostream> 
using std::cout; 
class main  
{ 
public: 
    main()  {cout << "ctor is called\n";} 
    ~main() {cout << "dtor is called\n";} 
}; 
int main()  
{ 
    main m;    // LINE 11 
}

Output: 
Compiler error:
11 8 [Error] expected ';' before 'm' 
The above program looks syntactically correct but it fails in compilation. The reason class name. Class name is main so
it is necessary to tell the compiler that main is the name of class. Generally struct or class keyword is not required to
write to create an object of the class or struct. But when the name of class is main it becomes necessary to write struct 
or class when creating object of class or struct. Remember main is not a reserved word.

Following is a correct version of the above program:

#include <iostream> 
using std::cout; 
class main 
{ 
public: 
   main()  { cout << "ctor is called\n";} 
   ~main() { cout << "dtor is called\n";} 
}; 
int main() 
{ 
   class main m; 
}

Now predict the output of following program:

#include <iostream> 
using std::cout; 
class main  
{ 
public: 
   main()  { cout << "ctor is called\n"; } 
   ~main() { cout << "dtor is called\n"; } 
}; 
main m;    // Global object 
int main() 
{              
}

The above program compiles and runs fine because object is global. Global object???s constructor executes before main() function
and it???s destructor executes when main() terminates.
Conclusion: When the class/struct name is main and whenever the local object is created it is mandatory to write class or 
struct when the object of class / and struct is created. Because C++ program execution begins from main () function.
But this rule is not applied to global objects. Again, main isn???t a keyword but treat it as if it were.

===========================================================================================

#include <iostream> 
using namespace std; 
int main() 
{ 
    char array[3] = "abc"; // Error 
    cout << array;     
    return 0; 
} 

output:
    It is not like C. Here size of string must be less then the size of array to accomodate

the null chararcter('\0').

#include <iostream> 
using namespace std; 
int main() 
{ 
    cout << sizeof('x'); 
    cout << sizeof(char);     
    return 0; 
} 

Output:
1 1
Explanation: It is notable that character constants are stored as character type in C++ but this is not the case in C.
In ANSI C, the same program would produce the result ??? 

4 1     // result when code is executed in C
because character constants are promoted to int.

===============================================================================================
#include <iostream> 
using namespace std; 
int main() 
{ 
    const int size; 
    cout << size; 
    return 0; 
} 

Output:
error: uninitialized const 'size'

Explanation: At first glance its obvious to think that output will be some garbage value, but it is not the case.
Unlike C in C++ any variable declared as constant needs to be initialized at the time of declaration.
Hence the given code will not compile and throw the error. It should be noted that the same code will get compiled
in ANSI C and will produce output as 0. 

====================================================================================================





































