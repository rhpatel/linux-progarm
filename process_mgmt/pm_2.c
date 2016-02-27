#include<stdio.h>
#include<unistd.h>

main(int argc,char **argv)
{

if(argc<=1)
 {
  printf("usage: ./a.out cmd\n");
  return;
 }

execvp(argv[1],argv+1);
 
}


