#include"header.h"

int count(B *ptr)
{int c=0;

 while(ptr)
 {
  c++;
  ptr=ptr->next;
 }
return c;
}



