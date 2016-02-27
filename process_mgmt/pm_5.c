#include<stdio.h>
#include<unistd.h>
main(int argc,char **argv)
{

int i;

for(i=1;argv[i];i++)
{
if(fork()==0)
 {
  execlp(argv[i],argv[i],NULL);
//  system(argv[i]);
 // break;
 }
else
;
//wait(0);
} 

}

