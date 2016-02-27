#include<unistd.h>
#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
void my_isr(int n)
{
	;
}
main()
{
	char s[10];
	int fd,i,a;

	signal(SIGUSR1,my_isr);
		if((a=fork())==0)
		{
			pause();
			printf("In child\n");
			fd=open("data",O_RDONLY);
			read(fd,s,sizeof(s));
			for(i=0;s[i];i++)
			{
				if(s[i]>='a' && s[i]<='z')
					s[i]=s[i]-32;
			}
			close(fd);
			fd=open("data",O_WRONLY|O_CREAT|O_TRUNC,0644);
			write(fd,s,strlen(s)+1);


		}

		else
		{
			printf("enter the data\n");
			scanf("%s",s);
			fd=open("data",O_WRONLY|O_CREAT|O_TRUNC,0644);
			write(fd,s,strlen(s)+1);
			kill(a,SIGUSR1);
		}




}






