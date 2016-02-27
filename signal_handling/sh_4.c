#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
static int  p;
void my_isr(int n)
{
printf("Child Exited\n");
wait(0);
}


main()
{
p=fork();
if(p==0)
{
int n;
srand(getpid());
n=rand()%10;
sleep(n);
}
else
{
signal(SIGCHLD,my_isr);
printf("%d",p);
while(1);
}
}




