#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>

main()
{
	int id,*c;
	int n;
	id=shmget(5,50,IPC_CREAT|0644);
	if(id<0)
	{
	perror("shmget");
	return;
	}
	printf("ID=%d\n",id);
	c=shmat(id,0,0);

	srand(getpid());
	n=rand()%1001;
	printf("Random number=%d\n",n);

	*c=n;
	printf("%d\n",*c);
	sleep(5);
	printf("%d\n",*c);



}


