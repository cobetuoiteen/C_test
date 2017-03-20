#include <stdio.h>

void main()
{
	int x, y, z;

	x = y = 10;
	z = (y = 3) + x + (y = 100) + (x = 6) ;

	printf("%d\n",z);

}
