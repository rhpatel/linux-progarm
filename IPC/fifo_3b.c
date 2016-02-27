#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<dirent.h>
main()
{

	int fd1,fd2,count=0;
	char path[100];
	mkfifo("f1",0644);
	mkfifo("f2",0644);
	fd1=open("f1",O_RDONLY);
	read(fd1,path,sizeof(path));
        printf("%s\n",path); 
	DIR *dp;
	struct dirent *p;
        dp=opendir(path);
	while(p=readdir(dp))
	{
	if(p->d_name[0]!='.')
	count++;
 	}
//	printf("Count=%d\n",count);

	fd2=open("f2",O_WRONLY);
	write(fd2,&count,sizeof(count));

	

}

