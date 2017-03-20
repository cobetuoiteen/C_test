#include <stdio.h>
void main()
{
	//khai bao ky tu dac biet : %
	char spec_char[] = "%";
	
	//khai bao kieu int
	int int_x = 10;
	printf("This is interger, to print it, use %sd : ", spec_char);
	printf("%d \n", int_x);
	
        //khai bao kieu float
        float float_x = 10.1234567890123456789;
        printf("This is float, to print it, use %sf : ", spec_char);
        printf("%f \n", float_x);

        //khai bao kieu double
        double double_x = 10.1234567890123456789;
        printf("This is double, to print it, use %sf : ", spec_char);
        printf("%f \n", double_x);

        //khai bao kieu char
        char char_x[] = "a";
        printf("This is char, to print it, use %ss : ", spec_char);
        printf("%s \n", char_x);

        //khai bao kieu int
        int x = 10;
        printf("This is interger, to print it, use %sd : ", spec_char);
        printf("%d \n",x);

	//getchar();
}
