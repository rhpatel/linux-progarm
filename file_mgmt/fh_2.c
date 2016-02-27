#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("Usage: ./a.out fname1 fname 2 \n");
		return;
	}

	struct stat v1,v2;

	stat(argv[1],&v1);
	stat(argv[2],&v2);

	printf("size of file %s =%d\n size of file %s =%d\n",argv[1],v1.st_size,argv[2],v2.st_size);

	if(v1.st_size>v2.st_size)
		printf("%s is bigger\n",argv[1]);
	else
		printf("%s is bigger\n",argv[2]);



}


