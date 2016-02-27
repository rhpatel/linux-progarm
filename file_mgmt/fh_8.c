#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

main(int argc,char **argv)
{

if(argc!=3)
{
printf("Usage: ./a.out s_file d_file");
return;
}
int fd1,fd2;
char *c;
fd1=open(argv[1],O_RDONLY);
fd2=open(argv[2],O_CREAT|O_WRONLY|O_TRUNC,0644);

while(read(fd1,&c,1)!=0)
{
write(fd2,&c,1);
}
}





