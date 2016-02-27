#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
int c=0;
int scr(char *,char *);
main(int argc,char **argv)
{
	int c=0;
	if(argc==2)
		c=scr(".",argv[1]);
	else if(argc==3)
		c=scr(argv[1],argv[2]);
	else
	{
		printf("Usage: ./a.out path fname\n\t ./a.out fname\n");
		return;
	}
	printf("count=%d\n",c);
}

int scr(char *path,char *f)
{
	char a[500]={'\0'},s[500]={'\0'};
	//	char *s,*a;
	DIR *dp;
	struct dirent *p;
	struct stat v;
	dp=opendir(path);
	if(dp==0)
	{
		perror("opendir");
		return;
	}             
	while(p=readdir(dp))
	{ strcpy(a,path);                //change the directories......
		strcat(a,"/");
		strcat(a,p->d_name); 
		printf("%s\n",a);
		if(p->d_name[0]!='.')
		{
			stat(a,&v);
			if(S_ISDIR(v.st_mode))
			{
				//               printf("%s is directory\n",p->d_name);
				scr(a,f);   
			}
			else if((strcmp(p->d_name,f))==0)
			{
				c++;
			}
		}
	}
	return c;
}



