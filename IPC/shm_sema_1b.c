#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<sys/sem.h>

main()
{
	
	int id,id1,*c;
	int n,num1=0;
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
  	v.sem_num=0;
	v.sem_flg=0;
      
	c=shmat(id,0,0);
        semop(id1,&v,1);		//wait for semaphore to 0 unlock.....
	printf("Received Num=%d\n",*c);
	n=*c;
	while(n)
	   {
		num1=(num1*10)+(n%10);
		n=n/10;
	   }
	printf("Rev Num=%d\n",num1);
	*c=num1;
	
	semctl(id1,1,SETVAL,0);      //unlock semaphore 1;
 
}


