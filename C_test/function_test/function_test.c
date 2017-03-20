#include <stdio.h>
#include <function_lib_test.h>

// compilre with command : gcc -o function_test function_test.c -Wall -I ./

int main()
{ 
	
	int *a, *b;
	int x = 2, y = 5;
	
	a = &x;
	b = &y;
	
	printf("\ntruoc khi swap : x = %d, y = %d\n\n", x, y);	
	printf("swap_with_pointer\n\n");
	swap_with_pointer( a , b );
	printf("sau khi swap : x = %d, y = %d\n\n", x, y);
	
	printf("truoc khi swap : x = %d, y = %d\n\n", x, y);
	printf("swap_without_pointer\n\n");
	swap_without_pointer( x , y );
	printf("sau khi swap : x = %d, y = %d\n\n", x, y);
	
	printf("truoc khi swap : x = %d, y = %d\n\n", x, y);
	printf("swap_with_poointer_use_variable\n\n");
	swap_with_pointer( &x , &y );
	printf("sau khi swap : x = %d, y = %d\n\n", x, y);

	return 0;
}
