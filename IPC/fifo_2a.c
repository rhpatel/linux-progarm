#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
main()
{
int fd1,fd2,i=0,j=0,k=0;
char s[30],s1[30],s2[30];
mkfifo("f1",0644);
mkfifo("f2",0644);
fd1=open("f1",O_WRONLY);
printf("Ente the data\n");
scanf("%s",s);
write(fd1,s,strlen(s)+1);

fd2=open("f2",O_RDONLY);
read(fd2,s,sizeof(s));

 for(k=0;s[k];k++)
           {  printf("%c\n",s[k]);
                if(s[k]>='a' && s[k]<='z')
                        s1[i++]=s[k];
                else if(s[k]>='0' && s[k]<='9')
                        s2[j++]=s[k];
        }
        s1[i]='\0';
        s2[j]='\0';


printf("data separated s1=%s\ns2=%s\n",s1,s2);

printf("data rec=%s\n",s);


}
