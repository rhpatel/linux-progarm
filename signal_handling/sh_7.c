#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int a[3],x,i,j,k;
void my_isr(int n)
{
	x++;

	if(x==1)
	{
		if(i==1)
			printf("child 1 terminate Normally\n");
		else  
		{
			kill(a[0],9);
			printf("Child 1 killed\n");
		}
	}
	else if(x==2)
	{
		if(j==1)
			printf("Child 2 terminate Normally\n");
		else
		{
			kill(a[1],9);
			printf("Child 2 killed\n");
		}
	}

	else if(x==3)
	{
		if(k==1)
			printf("child 3 terminate Normally\n");
		else
		{
			kill(a[2],9);
			printf("Child 1 killed\n");
		}
	}	

	alarm(2);

}

main()
{
	int n,s;
	signal(SIGALRM,my_isr);
	if((a[0]=fork())==0)
	{
		//child 1
		srand(getpid());
		n=rand()%11;
		printf("delay in child 1=%d\n",n);
		sleep(n);
		printf("After sleep in chld 1\n");
		exit(1);

	}
	else
	{
		if((a[1]=fork())==0)
		{
			//child 2
			srand(getpid());
			n=rand()%11;
			printf("delay in child 2=%d\n",n);
			sleep(n);
			printf("After sleep in chld 2\n");
			exit(2);

		}
		else
		{
			if((a[2]=fork())==0)
			{
				//child 3
				srand(getpid());
				n=rand()%11;
				printf("delay in child 3=%d\n",n);
				sleep(n);
				printf("After sleep in chld 3\n");
				exit(3);
			}
			else
			{
				//parent
				alarm(4);
				while(wait(&s)!=-1);
				{
					s>>8;
					if(s==1)
						i=1;
					else if(s==2)
						j=1;
					else if(s==3)
						k=1;
				}

			}

		}
	}

}
