#include<stdio.h>
#include<stdlib.h>

int stack[30];
int n=30;
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

void display()
{
	int i;
	if(top<0)
	{
		printf("\nThe stack is empty.");
	}
	else
	{
		printf("\n The elements of the stack are: ");
		for(i=top;i>=0;i--)
		{
			printf("%d\t",stack[i]);
		}
	}
	
}

void main()
{
	int i,num,choice;
	char ch;
	do
	{
		printf("\n1. For Push.");
		printf("\n2. For Pop.");
		printf("\n3. For Display.");
		printf("\nEnter your Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: if(top==n-1)
			{
				printf("\nStack is Full.");
			}
			else
			{
				printf("\n Enter the element you want to insert: ");
				scanf("%d",&num);
				push(num);
				display();
			}
			break;
			case 2: if(top<0)
			{
				printf("\nStack is Empty.");
			}
			else
			{
				num=pop();
				printf("The number deleted is %d",num);
				display();
			}
			break;
			case 3: display();
			break;
			default: printf("Invalid Choice");
		}
		printf("\n Do you want to continue: ");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');
	
}