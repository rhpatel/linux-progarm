#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
main()
{
	int d;
	if(fork()==0)
	{
		srand(getpid());
		d=rand()%10;
                printf("c1 sleep=%d\n",d);
         	sleep(d);
                printf("c1 after sleep\n");
		exit(1);
	}

	else
	{
		if(fork()==0)
		{
			srand(getpid());
			d=rand()%10;
                        printf("c2 sleep=%d\n",d);
			sleep(d);
                        printf("c2 after sleep\n");
			exit(2);
		}
		else
		{
			if(fork()==0)
			{    
				srand(getpid());
				d=rand()%10;
                                printf("c3 sleep=%d\n",d);
				sleep(d);
                		printf("c3 after sleep\n");
				exit(3);
			}
			else
			{int status;
				while(wait(&status)!=-1)
				{ 
                              
					if(status>>8==2)
					{
                                          	printf("child 2 is exited\n");
					break;
                                        }		    
                              	}

			}


		}
	}

} 

