#include<stdio.h>

int main()
{
scanf(" %s",input_buf);
do
{
type=get_next_token();
switch(type)
{
case INT: printf("type is integer");
          break;
case ID: printf("type is identifier");
          break;
case EOL: printf("type is End of Line");
          break;
case ERR: printf("type is Error");
          break;
}
}while(type);
}