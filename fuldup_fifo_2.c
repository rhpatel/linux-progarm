#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

main()
{
char s[20];

mkfifo("f1",0644);
mkfifo("f2",0644);
int fd1,fd2;

if(fork()==0)
{
  fd2=open("f2",O_RDONLY);
  while(1)
  {
  read(fd2,s,sizeof(s));
  printf("%s\n",s);
  }
}

else
{
  fd1=open("f1",O_WRONLY);
  while(1)
  {
  printf("Enter the data\n");
  scanf("%s",s);
 write(fd1,s,strlen(s)+1);
  }
}
}




