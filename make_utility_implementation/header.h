#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
	int rollno;
	char name[10];
	float marks;
	struct student *next;
}B;


