#include"header.h"

void print(B *ptr)
{

	while(ptr)
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}

}

void print_rec(B *ptr)
{
	if(ptr)
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		print_rec(ptr->next);
	}
}

void print_rev_rec(B *ptr)
{
	if(ptr)
	{
		print_rev_rec(ptr->next);
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
	}

}

void print_rev(B *ptr)
{
	B *temp;
	int c;
	c=count(ptr);
	int i,j;
	for(i=0;i<c;i++)
	{
		temp=ptr;
		for(j=0;j<c-1-i;j++)
			temp=temp->next;
		printf("%d %s %f\n",temp->rollno,temp->name,temp->marks);
	}
}

void print_rev_n(B *ptr)
{
	B *temp,**p;
	int i,c;
	c=count(ptr);
	temp=ptr;
	p=malloc(sizeof(B*)*c);
	for(i=0;i<c;i++)
	{
		p[i]=temp;
		temp=temp->next;
	}
	for(i=c-1;i>=0;i--)
		printf("%d %s %f\n",p[i]->rollno,p[i]->name,p[i]->marks);
}

void rev_link(B *ptr)
{

	B *temp1,*temp2,v,*p;
	int i,j,c;
	c=count(ptr);
	temp1=ptr;
	for(i=0;i<c/2;i++)
	{temp2=ptr;
		for(j=0;j<c-i-1;j++)
			temp2=temp2->next;

                   v=*temp1;
              *temp1=*temp2;
             *temp2=v;
           p=temp1->next;
          temp1->next=temp2->next;
          temp2->next=p;

/*		v.rollno=temp1->rollno;
		strcpy(v.name,temp1->name);
		v.marks=temp1->marks;

		temp1->rollno=temp2->rollno;
		strcpy(temp1->name,temp2->name);
		temp1->marks=temp2->marks;


		temp2->rollno=v.rollno;
		strcpy(temp2->name,v.name);
		temp2->marks=v.marks;
*/
		temp1=temp1->next;
	}
}



























