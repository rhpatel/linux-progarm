#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
static int p;
void my_isr(int n)
{
	kill(9,p);
	if(n==SIGCHLD)
		printf("Terminate normally after delay\n");
	else
		printf("Terminate forcefully after 5 sec\n");

	raise(9);
}





main()
{
	int d;
	signal(SIGCHLD,my_isr);
	signal(SIGALRM,my_isr);
		if((p=fork())==0)
		{
			srand(getpid());
			d=rand()%11;
			printf("delay=%d\n",d);
			sleep(d);
		}
		else
		{
			alarm(5);
			while(1);
		}
}


