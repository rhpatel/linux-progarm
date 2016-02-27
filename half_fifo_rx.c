#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

main()
{

char a[20];
mkfifo("f1",0644);
mkfifo("f2",0644);

int fd1,fd2;

fd1=open("f1",O_RDONLY);
fd2=open("f2",O_WRONLY);

while(1)
{
read(fd1,a,sizeof(a));
printf("%s\n",a);
printf("Enter the data\n");
scanf("%s",a);
write(fd2,a,strlen(a)+1);
}

}





