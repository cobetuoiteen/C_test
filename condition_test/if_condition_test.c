#include <stdio.h>

int main()
{
	if ('a' > 'b')
	{
		printf("a > b\n");
	}
	else
	{
		printf("a < b\n");
	}

	int a = (0 ? 0 : 1);
	int b = 1 ? 0 : 1;
	
	printf("a = (0 ? 0 :1);");
	printf("b = 1 ? 0 : 1;");
	printf("a = %d , b = %d \n", a,b);

	return 0;
}
