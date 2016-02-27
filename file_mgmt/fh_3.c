#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
main(int argc,char **argv)
{
if(argc!=2)
{
printf("Usage: ./a.out fnamei\n");
return;
}
struct stat v;

stat(argv[1],&v);

if(S_ISREG(v.st_mode))
printf("Regular\n");
else if(S_ISDIR(v.st_mode))
printf("directory\n");
else if(S_ISCHR(v.st_mode))
printf("Character device\n");
else if(S_ISBLK(v.st_mode))
printf("block device\n");
else if(S_ISFIFO(v.st_mode))
printf("FIFO\n");
else if(S_ISLNK(v.st_mode))
printf("LINK\n");
else if(S_ISSOCK(v.st_mode))
printf("socket\n");
}	




