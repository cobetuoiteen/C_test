#include <stdio.h>

void main()
{
	//khoi tao mot mang co 80 ky tu
	char line[80] = {};
	
	printf("Moi ban nhap vao mot chuoi ky tu, toi da 80 ky tu (nhieu hon thi vao chinh sua suorce code) : \n");
	//nhap mang tu ban phim
	scanf("%[A-Za-z0-9.]", line);
	printf("%s\n", line);

	//getchar();
}
