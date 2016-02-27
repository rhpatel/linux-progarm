#include"header.h"
main()
{
	struct msqid_ds v;
	int i,n,id;
	n=msgctl(0,MSG_INFO,&v);
	printf("n=%d\n",n);
	for(i=0;i<=n;i++)
	{
		id=msgctl(i,MSG_STAT,&v);
		msgctl(id,IPC_RMID,0);


	}
}
