#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
main()
{

	char s[]="abcdefghijklmnop";
	int fd,i;
	struct flock v;

	fd=open("data",O_RDWR|O_APPEND|O_CREAT,0644);
	v.l_type=F_WRLCK;
	v.l_whence=SEEK_SET;
	v.l_start=0;
	v.l_len=0;
	printf("Before\n");
	fcntl(fd,F_SETLKW,&v);
	printf("after\n");
		for(i=0;s[i];i++)
		{
			write(fd,&s[i],1);
			sleep(1);
		}
	v.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&v);
	printf("Done\n");
}




