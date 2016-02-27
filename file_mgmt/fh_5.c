#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
main(int argc, char **argv)
{
	if(argc!=3)
	{
		printf("Usage: ./a.out fname1 fname 2\n");
		return;
	}

	struct stat v1,v2;

	stat(argv[1],&v1);
	stat(argv[2],&v2);
	if(v1.st_ino==v2.st_ino)
	{	
		lstat(argv[1],&v1);
		lstat(argv[2],&v2);
		if(v1.st_ino==v2.st_ino)
			printf("Hard link\n");
		else
			printf("Soft link\n");
	}
	else
		printf("No link\n");
}



