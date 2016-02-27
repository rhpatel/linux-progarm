#include"header.h"
main()
{
       printf("AAAAAAABBBBBBBBBBBBB\n");
	B *headptr=0;
	char ch;
        int c;
	do
	{
			add_begin(&headptr);
			printf("Do you want to add node Y/y  \n");
  			scanf(" %c",&ch);
	}while((ch=='Y')||(ch=='y'));
	print(headptr);
        printf("-----------------------\n");
	c=count(headptr);
        printf("count=%d\n",c);
}



