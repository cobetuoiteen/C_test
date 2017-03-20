#include <stdio.h>

int main (int argc, char *argv[])
{
  int count;

  printf ("This program was called with \"%s\".\n", argv[0]);

  if (argc > 1)
    {
      for (count = 1; count < argc; count++)
	{
	  printf("argv[%d] = %s\n", count, argv[count]);
	  printf("address : %p\n", argv[count]);
	  // note : cung la argv[count], nhng %s in ra GIA TRI, con %p in ra DIA CHI cua phan tu tuong ung trong mang
	  switch(count)
	  {
		case 1 :
			printf("Hello world\n\n");
			break;
		case 2 :
			printf("Hello Tien\n\n");
			break;
		case 3 :
			printf("Hello you\n\n");
			break;
		default:
			printf("argc has not defined yet\n\n");
			break;
	  }
	}
    }
  else
    {
      printf("The command had no other arguments.\n");
    }

  return 0;
}
