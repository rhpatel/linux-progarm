#include<stdio.h>
#include<unistd.h>
main()
{

if(fork()==0)
{
printf("child 1 pid=%d ppid=%d\n",getpid(),getppid());
}
	else
           {
             if(fork()==0)
                 {
                 printf("child 2 pid=%d ppid=%d\n",getpid(),getppid());
                 }
             else
		{
		   if(fork()==0)
                        {
                        printf("child 3 pid=%d ppid=%d\n",getpid(),getppid());
                        }
                   else
                        {
		        wait(0);
			wait(0);
			wait(0);  
			printf("parent 1 pid=%d ppid=%d\n",getpid(),getppid());
                 	}
                }
            }
}   
