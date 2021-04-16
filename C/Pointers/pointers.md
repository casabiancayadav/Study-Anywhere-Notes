	>>>>>>>>>  POINTERS<<<<<<<<<<

	1) int main()
	{
		int i;
		int *ptr = (int *)malloc(5*sizeof(int)); // Suppose address is 11000

		for(i=0; i<5; i++)
		{               // -----------
			ptr[i] = i; // |0|1|2|3|4|
						// -----------
		}

	PF("%d ",*ptr++); // o/p : 0         // ( * ( ptr++ ) ), post increment in address.  |0|1|2|3|4|  ->>addr(11001)

	PF("%d ",(*ptr)++); // o/p : 1       // first derefrence and then increment in value. |0|2|2|3|4| ->>addr(11001)

	PF("%d ",*ptr); // o/p : 2          // |0|2|2|3|4| ->>addr(11001)

	PF("%d ",*++ptr); // o/p : 2        // first increment in Address then dereference. |0|2|2|3|4| ->>addr(11002)

	PF("%d ",++*ptr);// o/p : 3         // First derefrence and then increment value.   |0|2|3|3|4| ->>addr(11002)

	PF("%d ",*ptr);

	}

	OUTPUT :
			0 1 2 2 3
			
	2) void pointer can't be derefrence. we must typecast before using it. 
	3)
