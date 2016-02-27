#include<stdio.h>
#include<unistd.h>
main()
{
if(fork()==0)
	{
	execlp("ls","ls","-l",NULL);
	}
	else
	 {
          if(fork()==0)
           {
            execlp("pwd","pwd",NULL);
           }
           else
             {
              if(fork()==0)
                {
               execlp("cal","cal",NULL);
                }
              else
                {
                wait(0);
                wait(0);
                wait(0);
                
                }
             }
          }


}

                



