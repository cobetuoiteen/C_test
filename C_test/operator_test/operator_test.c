#include <stdio.h>

int main()
{
	char a[] = "a";
	char b[] = "b";
	int x;

	printf("string a[] : %s ,", a);
	printf(" co dia chi la : %p\n", &a);
	
        printf("string b[] : %s ,", b);
        printf(" co dia chi la : %p\n", &b);
	
	//Relational Operators
	printf("10 >= 6 + 8 : %d\n", 10 >= 6 + 8 );
	printf("5 == 1 + 4 : %d\n", 5 == 1 + 4 );
	
	//Logical Operators
	printf("(5 > 6) && (4 < 10) :  %d\n", (5 > 6) && (4 < 10) );
        printf("(5 > 6) || (4 < 10) :  %d\n", (5 > 6) || (4 < 10) );
	printf("!(5 > 6) : %d\n", !(5 > 6) );
	printf("!(4 < 10) : %d\n", !(4 < 10) );
		
	//Bitwise Logical Operators
	printf("(5 & 6) : %d\n", (5 & 6) );
        printf("(5 | 6) : %d\n", (5 | 6) );
        printf("(5 ^ 6) : %d\n", (5 ^ 6) );
        printf("~5 : %d\n", ~5 );

	printf("Nhap 1 so nguyen x : \n");
	scanf("%d", &x);
	printf("~x : %d\n", ~x );
	
	return 0;	
}
