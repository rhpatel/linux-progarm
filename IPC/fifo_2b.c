#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
main()
{
	int fd1,fd2,i=0,j=0,l;
	char s[30],temp;


	mkfifo("f1",0644);
	mkfifo("f2",0644);
	fd1=open("f1",O_RDONLY);
	fd2=open("f2",O_WRONLY);
	read(fd1,s,sizeof(s));
	printf("data=%s\n",s);
	l=strlen(s);

	for(i=0;i<l;i++)
	{
		for(j=0;j<l-i-1;j++)
		{ 
			if(s[j]<s[j+1])
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}

	}

	printf("data after reverse=%s\n",s);

	write(fd2,s,strlen(s)+1);


}
