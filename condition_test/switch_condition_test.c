#include <stdio.h>

void main()
{
	switch('a' + 'b')
	{
		case 195:
			printf("a + b = 195\n");
		
		case 196:
			printf("dung switch nhung quen dung break o case 1\n");
			break;
		
		case ('a' + 'a'):
			printf("a + b = a + a\n");
			break;
		default:
			break;
	}
}
