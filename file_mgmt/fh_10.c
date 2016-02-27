#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
main(int argc,char **argv)
{
  
	if(argc!=3)
	{
		printf("Usage: ./a.out option f_name\n");
		return;
	}
	char s[200]={'\0'};
	int fd,id;
	id=dup(0);
	printf("id=%d\n",id);

	if((strcmp(argv[1],"-a"))==0)
		fd=open(argv[2],O_WRONLY|O_APPEND|O_CREAT,0644);

	else if((strcmp(argv[1],"-i"))==0)
	{
		fd=open(argv[2],O_WRONLY|O_APPEND|O_CREAT,0644);
		signal(2,SIG_IGN);
	}

	printf("fd=%d\n",fd);
        while(1)
       {
        read(id,&s,sizeof(s));
        printf("%s\n",s);
        write(fd,&s,strlen(s)+1);
        bzero(s,sizeof(s)); 
       }


}
