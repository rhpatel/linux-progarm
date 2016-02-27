#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void my_isr(int n)
{
	;
}
main()
{
	FILE *fp;
	int b,a,c,d;
	printf("Enter the value of a and b\n");
	scanf("%d %d",&a,&b);
/*      ////////        print in child   //////////////////
	if(fork()==0)
	{
		c=a+b;
		fp=fopen("data","w");
		fprintf(fp,"%d",c);
		kill(getppid(),10);
	}

	else
	{
		
		signal(10,my_isr);
                pause();
		int op;
		fp=fopen("data","r");
		fscanf(fp,"%d",&op);
		printf("sum=%d\n",op);
	}
*/ //////////////  print in parent ///////////////////////

   if((d=fork())==0)
   {            signal(10,my_isr); 
                pause(); 
		int op;
		fp=fopen("data","r");
		fscanf(fp,"%d",&op);
		printf("sum=%d\n",op);
                exit(0); 


   }
  
  else
  {

		c=a+b;
		fp=fopen("data","w");
		fprintf(fp,"%d",c);
                fclose(fp);
                kill(d,10);
                wait(0);
              //  waitpid(d,0,0);
           
  }



}





