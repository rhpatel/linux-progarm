#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
main()
{
int fd;
char s[30];
mkfifo("f1",0644);
fd=open("f1",O_WRONLY);
printf("Ente the data\n");
scanf("%s",s);
write(fd,s,strlen(s)+1);
}
