#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("Usage: ./a.out dir_name\n");
			return;
	}

	int fd1,fd2,count=0;
	mkfifo("f1",0644);
		mkfifo("f2",0644);
		fd1=open("f1",O_WRONLY);
	write(fd1,argv[1],strlen(argv[1])+1);

	fd2=open("f2",O_RDONLY);
	read(fd2,&count,sizeof(count));

	printf("Count=%d\n",count);

}

