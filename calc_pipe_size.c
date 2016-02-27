#include<stdio.h>
#include<unistd.h>
struct clc
{
int a,b,op,sum;
};
main()
{
int p[2],q[2];
struct clc v;
if((pipe(p)<0)||(pipe(q)<0))
{
perror("pipe");
return;
}

if(fork())
	{//in parent
	printf("Enter the two number\n");
	scanf("%d%d",&v.a,&v.b);
        printf("Enter the option\n1)add\n2)sub\n3)mul\n");
	scanf("%d",&v.op);
        write(p[1],&v,sizeof(v));
        read(q[0],&v,sizeof(v));
        printf("output=%d\n",v.sum);
	}

	else
	{
        read(p[0],&v,sizeof(v));
        if(v.op==1)
        v.sum=v.a+v.b;
        else if(v.op==2)
        v.sum=v.a-v.b;
        else if(v.op==3)
        v.sum=v.a*v.b;
        write(q[1],&v,sizeof(v));
       
        }
}
