#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<sys/sem.h>

main()
{
	
	int id,id1,*c;
	int n;
	id=shmget(5,50,IPC_CREAT|0644);    // create a shared memory....
	if(id<0)
	{
	perror("shmget");
	return;
	}
	printf("SHM ID=%d\n",id);
	
	id1=semget(5,2,IPC_CREAT|0644);  // create semaphore....
	if(id1<0)
	{
	perror("semget");
	return;
	}
	printf("SEM ID=%d\n",id);

  	struct sembuf v;
        v.sem_op=0;                   //wait for zero condition     
  	v.sem_num=1;
	v.sem_flg=0;

	semctl(id1,0,SETVAL,1);      //lock semaphore 0
	semctl(id1,1,SETVAL,1);     //lock semaphore 1

	c=shmat(id,0,0);             // write in shared memory
	srand(getpid());
	n=rand()%1001;
	printf("Random number=%d\n",n);
	*c=n;
	printf("%d\n",*c);
	semctl(id1,0,SETVAL,0);	

	semop(id1,&v,1);			//wait for unlock semaphore 1;	
	printf("Reverse Number=%d\n",*c);
}


