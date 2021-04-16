
>>>>>>>>>  FUNCATIONS<<<<<<<<<<

	1) Funcation can be decalare inside the funcation but can't define inside the funcation.
		i.e
		main()
			{
				----
				void fun();     // No Error
				----
				-----
			}

			void fun()
			{
				------
				------
			}

	2) If we do not mention any reture type of a funcation then by default it is integer.
	3) Two return statements should not come successively.
	4) a funcation can take 127 arguments in C.
	5) sizeof give the value of any funcation will always return type of funcation.
		i.e
			int fun(void)
			{
				return ANY_VALUE;
			}

		sizeof(fun); // output will be size of funcation return type.
