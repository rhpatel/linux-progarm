#include<stdio.h>
#include<unistd.h>
#include<string.h>
main()
{

	int p[2];
	pipe(p);
	char s[25];
	if(fork()==0)
	{
	while(1)
	{
	read(p[0],s,sizeof(s));
	printf("data=%s\n",s);
	}
	}
	else
	{
	while(1)
	{
	printf("Enter the data\n");
	scanf("%s",s);
	write(p[1],s,strlen(s)+1);
	}
	}
}


