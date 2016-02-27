#include<stdio.h>
#include<unistd.h>
#include<signal.h>
main()
{
signal(SIGHUP,SIG_IGN);
printf("In pgm pid=%d\n",getpid());
while(1);
}
