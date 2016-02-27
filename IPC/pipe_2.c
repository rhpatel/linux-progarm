#include<stdio.h>
#include<unistd.h>
#include<string.h>
main()
{

	int p[2];
	pipe(p);
	int s;
	if(fork()==0)
	{
	while(1)
	{
	read(p[0],&s,sizeof(s));
	printf("data=%d\n",s);
	}
	}
	else
	{
	while(1)
	{
	printf("Enter the data\n");
	scanf("%d",&s);
	write(p[1],&s,sizeof(s));
	}
	}
}


