#include <stdio.h>

int main()
{
    int number;
    int *pnum;
    
    number = 3;
    pnum = &number;
        
    printf("number: %d\n", number);
    printf("&number: %p\n", &number);

    printf("Pnum: %p\n", pnum);
    printf("*Pnum: %d\n", *pnum);

//     printf(".......\n");
//     
//     pnum = NULL;
//     
//     printf("number: %d\n", number);
//     printf("&number: %p\n", &number);
// 
//     printf("Pnum: %p\n", pnum);
//     printf("*Pnum: %d\n", *pnum);

    printf(".......\n");

    char s[] = "01234567890";

    printf("&s[0]: %s\n", &s[0]);
    printf("s[5]: %d\n", s[5]);
    
    return 0;
}
