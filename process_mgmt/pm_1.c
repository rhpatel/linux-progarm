#include<stdio.h>
main()
{

	if(fork()==0)
	{      
        //	printf("ls cmd\n");
		system("ls");
		if(fork()==0)
		{       
		     	//printf("pwd cmd\n");
	         	system("pwd");
			if(fork()==0)
			{
			//	printf("calculator\n");
				system("cal");
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
        wait(0);
        }


}


