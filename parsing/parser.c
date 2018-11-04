#include<stdio.h>
#define isUpper(c) ((c)>='A'&&(c)<='Z')
char stack[10];
int top=-1;// pointing top of stack
char str[10];// the input string
int lookhead=0;//the pointer to the input string
char lookup_nt[]={'E','A','T','B','F'}; // set of non terminals
char lookup_t[]={'i','+','*','(',')','n'}; //set of terminals (n for end of input)
char parse_table[5][6][3]={"TA","","","TA","","",
"","+TA","","","#","#",
"FB","","","FB","","",
"","#","*FB","","#","#",
"i","","","(E)","",""
};//parse table
void push(char);
char pop();
int find(char);// to return the index of nt or t in parse table
void input();//to validate the input string
int resolve(char);// to check if the productions result to the string
/*
(i*i)n
(i+i)*in 
etc
*/
int main()
{
printf("Enter the input: ");
scanf("%s",str);
input();
}
void push(char c)
{
   stack[++top]=c;
}
void input()
{
   push('n');
   push('E');
while(1)
{
     if(stack[top]==str[lookhead])//if stack top and string lookhead symbol are same
        {
           if(str[lookhead]!='\0')
                {
                    top--;
                    lookhead++;
                }
           else//if reached end of input
                {
                	printf("VALID");
                    break;
                }
        }
     else if(isUpper(stack[top]))//if stack top consists of a non terminal
        {
          if(!resolve(stack[top]))//resolve the non terminal
                break;
        }
     else if(stack[top]=='#')
        {
           pop();
        }
     else
        {
           break;
        }
}
}
int resolve(char c)
{
int i;
int row=find(c);//terminal parse table index
int col=find(str[lookhead]);//non terminal parse table index
if(row!=-1&&col!=-1&&parse_table[row][col]!="")
{
        pop();
        for(i=0;parse_table[row][col][i]!='\0';i++);
        for(i=i-1;i>=0;i--)
        push(parse_table[row][col][i]);
        return 1;
}
else
{
        printf("\nnot a valid character:%c at the position %d",str[lookhead],lookhead+1);
        return 0;
}
}
char pop()
{
        return stack[top--];
}
int find(char c)
{
        int i;
        if(isUpper(c))//for non terminal
          {
             for(i=0;lookup_nt[i]!='\0';i++)
                if(lookup_nt[i]==c)
                  return i;
             return -1;
          }
        else//for terminal
          {
             for(i=0;lookup_t[i]!='\0';i++)
                if(lookup_t[i]==c)
                   return i;
             return -1;
          }
}
