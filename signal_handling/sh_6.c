#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void my_isr(int n)
{
	static int a=3,b=5;
	if(n==2)
	{
		a--;
		if(a==0)
		{
			signal(SIGINT,SIG_DFL);
		}
	}
	if(n==3)
	{
		b--;
		if(b==0)
		{
			signal(SIGQUIT,SIG_DFL);
		}
	}
}

main()
{
	signal(SIGINT,my_isr);
	signal(SIGQUIT,my_isr);
	while(1);
}

