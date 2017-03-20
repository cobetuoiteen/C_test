//io
#include <stdio.h>
// __fpurge(stdin);
#include <stdio_ext.h>

int main() 
{
	int x;
	char s[100];

	// scan a number
	printf("enter number x = ");
	scanf("%d", &x);

	// clear stdin
	__fpurge(stdin);

	// scan a string
	printf("enter a string: ");
	gets(s);

	printf("number is %d \nstring is %s\n", x,s);
	return 0;
}
