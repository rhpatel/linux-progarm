#include"header.h"

void add_begin(B **ptr)
{
	B *new;
	new=malloc(sizeof(B));
	printf("Enter the rollno name and marks,,\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	new->next=*ptr;
	*ptr=new;
}


void add_end(B **ptr)
{
	B *new,*old,*temp;
	new=malloc(sizeof(B));
	printf("Enter the rollno name and marks,,\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);
	if(*ptr==0)
	{
		new->next=*ptr;
		*ptr=new;
	}
	else
	{
		temp=*ptr;
		while(temp)
		{
			old=temp;
			temp=temp->next;
		}
		new->next=old->next;
		old->next=new; 
 	}
}

void add_middle(B **ptr)
{
	B *new,*old,*temp;
	new=malloc(sizeof(B));
	printf("Enter the rollno name and marks,,\n");
	scanf("%d %s %f",&new->rollno,new->name,&new->marks);

	if(*ptr==0 ||(*ptr)->rollno>new->rollno)
	{
		new->next=*ptr;
		*ptr=new;
	}
	else
	{old=*ptr;
		while(old)
		{ 
			if(old->next==0||old->next->rollno>new->rollno)
			{       if(old->rollno==new->rollno)
                                  {
                                    printf("Data Duplication\n");
                                    return;
                                  }
                                   
				new->next=old->next;
				old->next=new;
				break;
			}
			old=old->next;
		}
	}                       
}              



