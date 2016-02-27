#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<grp.h>
#include<pwd.h>
#include<time.h>

main(int argc, char **argv)
{
	DIR *dp;
	struct dirent  *p;
	struct stat v;
	struct group *v1;
	struct passwd *v2;
	dp=opendir(".");
	time_t t1;
	char c[25]=" ";
	char c1,s1[4]=" ",s2[4]=" ",s3[4]=" ";
	unsigned int m1,m2,m3,i,j;
	if(dp==0)
	{
		perror("opendir");
		return;
	}

	while(p=readdir(dp))
		if(p->d_name[0]!='.')
		{

			stat(p->d_name,&v);
			t1=v.st_mtime; 
			strcpy(c,ctime(&t1));
			c[strlen(c)-1]='\0';

			{
				if(S_ISREG(v.st_mode))
					c1='-';
				else if (S_ISDIR(v.st_mode))
					c1='d';
				else if (S_ISCHR(v.st_mode))
					c1='c';
				else if (S_ISBLK(v.st_mode))
					c1='b';
				else if (S_ISFIFO(v.st_mode))
					c1='p';
				else if (S_ISLNK(v.st_mode))
					c1='l';
				else if (S_ISSOCK(v.st_mode))
					c1='s';
			}
			m1=(v.st_mode&0700)>>6;
			m2=(v.st_mode&0070)>>3;
			m3=v.st_mode&0007;
			if(m1==0)
				strcpy(s1,"---");
			else if (m1==1)
				strcpy(s1,"--x");
			else if (m1==2)
				strcpy(s1,"-w-");
			else if (m1==3)
				strcpy(s1,"-wx");
			else if (m1==4)
				strcpy(s1,"r--");
			else if (m1==5)
				strcpy(s1,"r-x");
			else if (m1==6)
				strcpy(s1,"rw-");
			else if (m1==7)
				strcpy(s1,"rwx");

			if(m2==0)
				strcpy(s2,"---");
			else if (m2==1)
				strcpy(s2,"--x");
			else if (m2==2)
				strcpy(s2,"-w-");
			else if (m2==3)
				strcpy(s2,"-wx");
			else if (m2==4)
				strcpy(s2,"r--");
			else if (m2==5)
				strcpy(s2,"r-x");
			else if (m2==6)
				strcpy(s2,"rw-");
			else if (m2==7)
				strcpy(s2,"rwx");

			if(m3==0)
				strcpy(s3,"---");
			else if (m3==1)
				strcpy(s3,"--x");
			else if (m3==2)
				strcpy(s3,"-w-");
			else if (m3==3)
				strcpy(s3,"-wx");
			else if (m3==4)
				strcpy(s3,"r--");
			else if (m3==5)
				strcpy(s3,"r-x");
			else if (m3==6)
				strcpy(s3,"rw-");
			else if (m3==7)
				strcpy(s3,"rwx");
			v1=getgrgid(v.st_gid);
			v2=getpwuid(v.st_uid);
			printf("%c%s%s%s %d %s %s %ld %s %s\n",c1,s1,s2,s3,v.st_nlink,v1->gr_name,v2->pw_name,v.st_size,c,p->d_name);


		}
}

