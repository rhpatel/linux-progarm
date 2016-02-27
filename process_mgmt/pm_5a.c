#include<stdio.h>
#include<stdlib.h>

main(int argc,char **argv)
{int i;
if(argc==1)
{
 printf("Usage : ./a.out cmd cmd cmd....\n");
 return;
}
for(i=1;argv[i];i++)
{
 system(argv[i]);
}
}





