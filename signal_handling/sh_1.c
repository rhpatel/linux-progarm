#include<stdio.h>
#include<signal.h>
static int a=7;
void my_isr(int n)
{
a--;
	if(a==0)
	raise(9);
	else
        {
        printf("IN ISR a=%d\n",a);
	alarm(a);
        }
}


main()
{
	signal(SIGALRM,my_isr);
	alarm(a);
	while(1);
}




