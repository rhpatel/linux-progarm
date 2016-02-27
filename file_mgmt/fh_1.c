#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
main(int argc,char **argv)
{
if(argc!=2)
{
printf("Usage: ./a.out fname\n");
return;
}

struct stat v;

stat(argv[1],&v);

printf("size of file =%d\n",v.st_size);
}


