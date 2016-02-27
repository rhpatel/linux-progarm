#include<stdio.h>
#include<unistd.h>

main()
{
	printf("p=%d ppid=%d\n",getpid(),getppid());
	if(fork()==0)
	{
		printf("p1=%d ppid=%d\n",getpid(),getppid());
		system("ls");
		if(fork()==0)
		{
			printf("p2=%d ppid=%d\n",getpid(),getppid());
			system("pwd");
			if(fork()==0)
			{
				printf("p3=%d ppid=%d\n",getpid(),getppid());
				system("cal");
			}
			else
			{
				wait();
			}

		}
		else
		{
			wait();
		}
	}
	else
	{
		wait();
	}
}   
