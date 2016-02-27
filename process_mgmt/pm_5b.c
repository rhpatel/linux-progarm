#include<stdio.h>
#include<unistd.h>
main(int argc,char **argv)
{
int i;
if(argc<=1)
{
printf("usage: ./a.out cmd cmd cmd...=\n");
return;
}

for(i=1;argv[i];i++)
{
 if(fork()==0)
   {
    execlp(argv[i],argv[i],NULL);
   }
 else
  {
  wait(0);
  }
}
//while(1);
}






