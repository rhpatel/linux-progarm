#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/msg.h>
struct msgbuf
	{
	int mtype;
	char data[20];
	};

main()
{

struct msgbuf v;
int id;
id=msgget(5,0);
int j;

while(j=(msgrcv(id,&v,sizeof(v.data),0,IPC_NOWAIT)))
{
if(j==-1)
break;
perror("msgrcv");
printf("data=%s\n",v.data);
sleep(1);
}

}

