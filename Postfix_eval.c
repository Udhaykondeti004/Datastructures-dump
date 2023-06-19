#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define MAXSIZE 40

int stack[MAXSIZE];
int top=-1;

void push(int num)
{
	top=top+1;
	stack[top]=num;
}
int pop()
{
	int num;
	num=stack[top];
	top=top-1;
	return num;
}

void main()
{
	char expr[40],ch;
	int i,val1,val2,res;
	printf("\n Enter a postfix expression: ");
	scanf("%s",expr);
	for(i=0;i<strlen(expr);i++)
	{
		ch=expr[i];
		if(isdigit(ch))
		{
			push(ch - '0');
		}
		if(ch=='+' || ch=='-' || ch== '*' || ch== '/'|| ch=='^')
		{
			switch(ch)
			{
				case '+': val1=pop();
						  val2=pop();
						  res=val2 + val1;
						  push(res);
						  break;
				case '-': val1=pop();
						  val2=pop();
						  res=val2 - val1;
						  push(res);
						  break;
				case '*': val1=pop();
						  val2=pop();
						  res=val2 * val1;
						  push(res);
						  break;
				case '/': val1=pop();
						  val2=pop();
						  res=val2 / val1;
						  push(res);
						  break;
				case '^': val1=pop();
						  val2=pop();
						  res = (int)(pow(val2,val1));
						  push(res);
						  break;
				default: printf("\n Invalid Option.");
			}
		}
		
	}
	
	printf("The result of the postfix expression is %d",pop());