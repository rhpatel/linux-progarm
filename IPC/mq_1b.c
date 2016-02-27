#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<fcntl.h>
struct msgbuf
{
	int mtype;
	struct data
	{
	int file;
	int link;
	char path[100];
	}q;
};

main()
{

	int id,a[2],count=0;

	id=msgget(5,IPC_CREAT|0644);
	if(id<0)
	{
		perror("msgget");
		return;
	}
	struct msgbuf v;
	msgrcv(id,&v,sizeof(v.q),2,0);
	printf("path=%s\n",v.q.path);      



  DIR *dp;
   	struct dirent *p1;
	struct stat v1;
        dp=opendir(v.q.path); 
	while((p1=readdir(dp))!=0)
	{
	if(p1->d_name[0]!='.')
	count++;
	}

	printf("No of files=%d\n",count);
        
        v.mtype=3;
	v.q.file=count;
	msgsnd(id,&v,sizeof(v.q),0);
	perror("msgsnd");
        
	lstat(v.q.path,&v1);
	printf("No of Hardlinks=%d\n",v1.st_nlink);
	
	v.mtype=4;
	v.q.link=v1.st_nlink;        
	msgsnd(id,&v,sizeof(v.q),0);

}






