#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>

main()
{
	int id,*c;
	int n,num1=0;
	id=shmget(5,50,IPC_CREAT|0644);
	if(id<0)
	{
	perror("shmget");
	return;
	}
	printf("ID=%d\n",id);
	c=shmat(id,0,0);
	printf("%d\n",*c);
	
	n=*c;
	while(n)
	{
	num1=(num1*10)+(n%10);
	n=n/10;
	}
	printf("%d\n",num1);
	*c=num1;
				


}


