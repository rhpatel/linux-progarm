#include<stdio.h>
main()
{


        printf("pid p=%d ppid=%d\n",getpid(),getppid());
	if(fork()==0)
	{
		system("ls");
                printf("pid c1=%d ppid=%d\n",getpid(),getppid());
	}
	else
	{
         	wait();
		if(fork()==0)
		{
			system("pwd");
                        printf("pid c2=%d ppid=%d\n",getpid(),getppid());
		}
		else
		{
 		wait();
                     if(fork()==0)
                      {
                        system("cal");
                        printf("pid c3=%d ppid=%d\n",getpid(),getppid());
		      }
                     else
                    { 
                   wait();
  
                           //wait();
                           //wait();
                           printf("pid p1=%d ppid=%d\n",getpid(),getppid());
                      }
                 
	         }                 
           }
}
                     
                        
