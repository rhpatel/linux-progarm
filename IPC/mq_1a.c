#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>

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

main(int argc, char **argv)
{

	if(argc!=2)
	{
		printf("usage: ./a.out path/dir\n");
		return;
	}

	int id,a[2];
	struct msgbuf v,v1;
	id=msgget(5,IPC_CREAT|0644);
	if(id<0)
	{
		perror("msgget");
		return;
	}

	v.mtype=2;
	strcpy(v.q.path,argv[1]);
	printf("%s\n",v.q.path);
        msgsnd(id,&v,sizeof(v.q),0);

	v.mtype=3;
	msgrcv(id,&v,sizeof(v.q),3,0);
	perror("msgrcv");
	printf("files=%d",v.q.file);
	v.mtype=4;
	msgrcv(id,&v,sizeof(v.q),4,0);
	perror("msgrcv");
	printf("Hardlink=%d",v.q.link);

}






