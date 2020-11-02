#include <stdio.h>

struct _node
    {
        char a;
        double d;
        char c; 
    }node;

int main()
{

	printf("\n\n ==> %ld \n\n", sizeof( node ) );
	return 0;

}


