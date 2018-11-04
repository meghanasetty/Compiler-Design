/*
Program to werify if the statement is valid or not. 
*/
#define ID 256
#define PL 257  //+ operator
#define OP 258  // (
#define CP 259  // )
#define EOF 260 //End Of File
#include<stdio.h>
//int token_str[10]={ID,ID,OP,ID,PL,ID,CP,EOF}  is not valid according to the program
int token_str[10]={ID,PL,OP,ID,PL,ID,CP,EOF}; // is valid according to the program
int indx=-1;//a pointer to the input string
void getnext_token();//to get the next token in the statement
int input();//for taking the input statement
int token(int num);//checking if it is token
int expr();//checking if it is expression
int term();//if is term
int rest_expr();
int par_expr();//parentisised expr
int require(int num);//return true if num=1 else false
int main()
{
getnext_token();
if(require(input())) printf("valid statement");
else printf("not valid");
return 0;
}

void getnext_token()
{
indx++;
}
/*
input --> expr EOF
expr --> term rest_expr
term --> ID
		 | (expr)
rest_expr --> '+'expr
			 | (epsilon)
*/
int input()
{
return expr()&&require(token(EOF));
}
int token(int num)
{
if(token_str[indx]==num)
{
getnext_token();
return 1;
}
else
{
return 0;
}
}

int expr()
{
return term()&&rest_expr();
}

int term()
{
return token(ID) || par_expr();
}

int par_expr()
{
return token(OP)&& require(expr())&&require(token(CP));
}

int rest_expr()
{
return (token(PL)&&require(expr()))|1;
}

int require(int num)
{
if (num==1)
{
return 1;
}
else
{
return 0;
}
}
