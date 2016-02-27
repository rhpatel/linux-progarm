#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<utime.h>
#include<time.h>
main(int  argc,char **argv)
{
	if(argc!=3)
	{
		printf("usage : ./a.our f_new f_old\n");
		return;
	}

	struct stat v,v1,v2;
	struct utimbuf u;

	lstat(argv[1],&v1);
	lstat(argv[2],&v2);
	printf("Before \n");
	printf("1st file\n");
	printf("file last access time %s",ctime(&v1.st_atime));
	printf("file last modification time %s\n",ctime(&v1.st_mtime));

	printf("2nd file\n");
	printf("file last access time %s",ctime(&v2.st_atime));
	printf("file last modification time %s\n",ctime(&v2.st_mtime));

	if(v1.st_mtime>v2.st_mtime)
	{  printf("HIT\n");
		u.actime=v2.st_atime;
		u.modtime=v2.st_mtime;
		utime(argv[1],&u);
	}
	else
	{
		u.actime=v1.st_atime;
		u.modtime=v1.st_mtime;
		utime(argv[2],&u);
	}

	lstat(argv[1],&v1);
	lstat(argv[2],&v2);

	printf("After\n");
	printf("1st file\n");
	printf("file last access time %s",ctime(&v1.st_atime));
	printf("file last modification time %s\n",ctime(&v1.st_mtime));

	printf("2nd file\n");
	printf("file last access time %s",ctime(&v2.st_atime));
	printf("file last modification time %s\n",ctime(&v2.st_mtime));
}


