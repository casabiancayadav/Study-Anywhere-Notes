
>>>>>>>>>  ENUMS<<<<<<<<<<

	1) Only integer constant are allowed into Enums
	2) All enum constant must be unique in their sccope. 
		i.e
			enum{
					a,b,c
				}HI;

			enum{
					c,d,e
				}HELLO;

    'C' can't be in same file with same scope.

    Can be declare Enum anywhere in file ? or in any funcaion. search scope means here.??????

	3) we can't modify the value of Enum constant.

	i.e
        Enum San{
					a,b,c=5
                };

			enum San s;

main()	{
            s++;                // No Error
			c++;                // Error can't modify
			printf("%d",c);
        }

	4) There is no physical memory for Enum constants only logical memory.
