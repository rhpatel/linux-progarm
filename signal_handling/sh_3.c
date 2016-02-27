#include<stdio.h>
#include<signal.h>
void find_isr(int n)
{
//signal(n,SIG_IGN);
struct sigaction v;
sigaction(n,NULL,&v);
if(v.sa_handler==SIG_DFL)
printf("default\n");
else if(v.sa_handler==SIG_IGN)
printf("Ignore\n");
else 
printf("my_ISR");
}


main()
{
int n;
printf("Enter the interrupt number\n");
scanf("%d",&n);
find_isr(n);
wait(0);
}
