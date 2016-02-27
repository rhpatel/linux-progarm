#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>
main(int argc,char **argv)
{
if(argc!=3)
{
printf("usage: ./a.out fname1 fname2\n");
return;
}

struct stat v1,v2;

lstat(argv[1],&v1);
lstat(argv[2],&v2);

printf(" file %s time=%ld sec\n and %s ",argv[1],v1.st_mtime,ctime(&v1.st_mtime));
 
printf(" file %s time=%ld sec\n and %s ",argv[2],v2.st_mtime,ctime(&v2.st_mtime));

if(v1.st_mtime<v2.st_mtime)
printf("%s is old\n",argv[1]);
else
printf("%s is old\n",argv[2]);

}
