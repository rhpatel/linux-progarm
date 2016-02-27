#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

void* thread1(void *p)
{
char s[50];
int fd;
fd=open("f1",O_WRONLY);
while(1)
{
scanf("%s",s);
write(fd,s,strlen(s)+1);
}
}


void* thread2(void *p)
{
int fd;
char s[50];
fd=open("f2",O_RDONLY);
while(1)
{
read(fd,s,sizeof(s));
printf("%s\n",s);
}
}

main()
{
mkfifo("f1",0644);
mkfifo("f2",0644);
pthread_t t1,t2;

pthread_create(&t1,NULL,thread1,NULL);
perror("pthread_create");
pthread_create(&t2,NULL,thread2,NULL);
perror("pthread_create");

while(1);
}


