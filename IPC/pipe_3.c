#include<stdio.h>
#include<unistd.h>
#include<string.h>
main()
{

	int p[2];
	pipe(p);
	char s;
	if(fork()==0)
	{
	while(1)
	{
	read(p[0],&s,sizeof(char));
	printf("data=%c\n",s);
	}
	}
	else
	{
	while(1)
	{
	printf("Enter the data\n");
	scanf(" %c",&s);
	write(p[1],&s,sizeof(char));
//	sleep(1);
	}
	}
}


