#include <stdio.h>

void main(int argc, char* argv[])
{
	// khoi tao mot mang, trong C cho phep tao mot mang voi so luong phan tu ko cho trc
	int n = 10;	
	int array_1[n];
	
	// khoi tao con tro
	int* p;
	
	//gan gia tri cho cac phan tu cua mang
	for (int i = 0; i < n; i++)
	{
		array_1[i] = i;
	}
	
	//kiem tra con tro p
	// p = &var => luu dia chi cua bien var vao p , vd : var = 3, &var = 0x01, &p = 0x15
	// Khi do : 
	//	p  : dia chi cua var ( = 0x01)
	//	*p : gia tri cua var ( = 3   )
	//	&p : dia chi cua p   ( = 0x15)
	p = &array_1[3];
	printf("con tro p tro vao phan tu array_1[3] chua gia tri %d tai dia chi %p, dia chi cua p : %p\n", *p, p, &p);
	p++;
        printf("p++ chua gia tri %d tai dia chi %p, dia chi cua p : %p\n", *p, p, &p);
	p++;
        printf("p++ chua gia tri %d tai dia chi %p, dia chi cua p : %p\n", *p, p, &p);
	
	// in gia tri do ra || co truy suat phan tu nam ngoai mang
	// gcc cho phep compile, compile thanh cong, run thanh cong
	for (int i = 0; i < (n + 5); i++)
	{
		if(i == 10)
		{
			printf("\ntruy suat phan tu nam ngoai mang ..........\n\n");
		}
		printf("array_1[%d] chua gia tri %d tai dia chi %p\n" , i, array_1[i], &array_1[i]);
	}	
}
