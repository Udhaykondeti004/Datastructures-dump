#include<stdio.h>
#include<string.h>

char stack[40];
int top=-1;
char postfix[30];
int size=-1;


int isOperand(char ch)
{
	if((ch>='a' && ch<='z') || (ch>='A' && ch<= 'Z')|| (ch>=0 && ch<=9))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void addToPostfix(char ch)
{
	size=size+1;
	postfix[size]=ch;
}

void push(char ch)
{
	top=top+1;
	stack[top]=ch;
}

char pop()
{
	char ch;
	ch=stack[top];
	top=top-1;
	return ch;
}

int precedence(char ch)
{
	if(ch=='+' || ch=='-')
	{
		return 1;
	}
	else if(ch=='*' || ch=='/')
	{
		return 2;
	}
	else if(ch=='^')
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

void main()
{
	char expr[40],ch;
	int i,len;
	printf("\nEnter an arithmetic expression: ");
	scanf("%s",&expr);
	len=strlen(expr);
	printf("\nThe length of the expression is : %d",len);
	for(i=0;i<len;i++)
	{
		if(isOperand(expr[i]))
		{
			printf("\nAn Operand is encountered.");
			addToPostfix(expr[i]);
		}
		else if(expr[i]=='(')
		{
			push(expr[i]);
		}
		else if(expr[i]==')')
		{
			ch=pop();
			while(ch!='(')
			{
				addToPostfix(ch);
				ch=pop();
			}	
		}
		else
		{
			printf("\nAn operator is encountered.");
			while(precedence(stack[top])>=precedence(expr[i]))
			{
				ch=pop();
				addToPostfix(ch);
			}
			push(expr[i]);
		}
		
	}
	postfix[++size]='\0';
	printf("\nThe equivalent postfix expression is %s:",postfix);
}