#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
main()
{
	int fd,i=0,j=0,k=0;
	char s[30],s1[30]={'\0'},s2[30]={'\0'};


	mkfifo("f1",0644);
	fd=open("f1",O_RDONLY);
	read(fd,s,sizeof(s));
      
     printf("data=%s\n",s);
	for(k=0;s[k];k++)
	{  printf("%c\n",s[k]);
		if(s[k]>='a' && s[k]<='z')
			s1[i++]=s[k];
		else if(s[k]>='0' && s[k]<='9')
			s2[j++]=s[k];
	}
	s1[i++]='\0';
	s2[j++]='\0';

printf("data separated s1=%s\ns2=%s\n",s1,s2);

}
