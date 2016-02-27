#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
main(int argc, char **argv)
{

	int i,j,k;
	if(argc!=2)
	{
		printf("usage: ./a.out cmdq,cmd2,cmd3...  \n");
		return;
	}        
		
         
     for(i=0;;i++)
    {
     if(argv[1][i]==',')
       argv[1][i]=';';

     if(argv[1][i]=='\0')
        break;
    }

  system(argv[1]);
}

    
              
   
      






