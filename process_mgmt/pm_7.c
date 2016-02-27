#include<stdio.h>
#include<unistd.h>
main()
{

if(fork()==0)
 { 
   printf("x+1 pid=%d ppid=%d\n",getpid(),getppid());
   if(fork()==0)
     {
  	printf("x+2 pid=%d ppid=%d\n",getpid(),getppid());
	if(fork()==0)
           {
 	    printf("x+3 pid=%d ppid=%d\n",getpid(),getppid());
           }
         else
	  {
           wait(0);
	  }
     }
   else
    {
     wait(0);
    }
}
else
{
printf("x pid=%d ppid=%d\n",getpid(),getppid());
wait(0);
} 

}


