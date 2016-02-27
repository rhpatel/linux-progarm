#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

main()
{
	FILE *fp;
	char **p,ch,s3[100],s1[50],s2[50];
	int line=0,size=0,i;
	struct stat v1,v2;
	fp=fopen("makefile","r");
	if(fp==0)
	{
		perror("fopen");
		return;
	}
	while((ch=fgetc(fp))!=EOF)
	{
		size++;
		if(ch=='\n')
			line++;
	}
	rewind(fp);
	p=malloc(sizeof(char *)*line);
	for(i=0;i<line;i++)
	{
		p[i]=malloc(size);
	}
	i=0;
	while(fgets(p[i++],size,fp));

//	for(i=0;i<line;i++)
//	printf("%s\n",p[i]);
      int k,l=0;
      for(i=2;i<line;i++)
	{
           strcpy(s3,p[i]);
	   for(k=0;s3[k]!=':';k++)
                s1[k]=s3[k];
                s1[k]='\0';

          l=0;     	 
          for(k=k+1;s3[k];k++)
             s2[l++]=s3[k];
 	     s2[l]='\0';			
        // printf("%s\n%s\n",s1,s2);
		lstat(s1,&v1);
		lstat(s2,&v2);
	   if(v2.st_mtime<v1.st_mtime)
		{
		printf(".c time=%u\n.o time%u\n",v2.st_mtime,v1.st_mtime);
                
             p[i+1][strlen(p[i+1])-1]=' ';  
            strcat (p[i+1],"-o ");
            strcat(p[i+1],s1);
            printf("%s\n",p[i+1]);         
                 system(p[i+1]);
	i++;
        }
}
       system(p[1]);
	//printf("line=%d size=%d\n",line,size);
}








