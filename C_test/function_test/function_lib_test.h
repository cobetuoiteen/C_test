int swap_with_pointer(int* a, int* b)
{
        printf("a: %d, b: %d\n", *a, *b);
        int* c;
        *c = *a;
        printf("a: %d, b: %d, c: %d\n", *a, *b, *c);

        *a = *b;
        printf("a: %d, b: %d, c: %d\n", *a, *b, *c);

        *b = *c;
        printf("a: %d, b: %d, c: %d\n", *a, *b, *c);

        return 0;
}

int swap_without_pointer(int a, int b)
{
        printf("a: %d, b: %d\n", a, b);
        int c;
        c = a;
        printf("a: %d, b: %d, c: %d\n", a, b, c);

        a = b;
        printf("a: %d, b: %d, c: %d\n", a, b, c);

        b = c;
        printf("a: %d, b: %d, c: %d\n", a, b, c);

        return 0;
}
/*
void swap_with_address(int &a, int &b)
{
        printf("a: %d, b: %d\n", a, b);
        int c;
        c = a;
        printf("a: %d, b: %d, c: %d\n", a, b, c);

        a = b;
        printf("a: %d, b: %d, c: %d\n", a, b, c);

        b = c;
        printf("a: %d, b: %d, c: %d\n", a, b, c);
}
*/
