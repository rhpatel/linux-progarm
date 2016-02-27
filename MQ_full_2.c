#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
struct msgbuf
{
	int mtype;
	char data[20];
};
main()
{
	struct msgbuf v;
	int id;

	id=msgget(5,IPC_CREAT|0644);
	if(id<0)
	{
		perror("msgget");
		return;
	}

	if(fork()==0)
	{
		while(1)
		{
			msgrcv(id,&v,sizeof(v.data),3,0);
			printf("%s\n",v.data);
		}
	}
	else
	{
		while(1)
		{
			printf("Enter the data\n");
			scanf("%s",v.data);
                        v.mtype=2;
			msgsnd(id,&v,strlen(v.data)+1,0);
		}
	}
}






