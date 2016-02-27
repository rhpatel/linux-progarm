#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<string.h>
struct msgbuf
{
	int mtype;
	char data[20];
};


main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("Usage: ./a.out msgtype data\n");
		return;
	}
	int id;
	struct msgbuf v;
	id=msgget(5,IPC_CREAT|0644);
		if(id<0)
		{
			perror("msgget");
			return;
		}

	v.mtype=atoi(argv[1]);
	strcpy(v.data,argv[2]);
	msgsnd(id,&v,strlen(v.data)+1,0);
	perror("msgsnd");
}
