#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5
int front=-1;
int rear=-1;
int cqueue[MAXSIZE];

void enqueue(int num)
{
	if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		cqueue[rear]=num;
	}
	else if(front==(rear+1)%MAXSIZE)
	{
		printf("\nQueue Overflow!");
	}
	else
	{
		rear=(rear+1)%MAXSIZE;
		cqueue[rear]=num;
	}
}
int dequeue()
{
	int num;
	if(front==-1)
	{
		printf("\n Queue is Empty!");
		return -999;
	}
	else if(front==rear)
	{
		num=cqueue[front];
		front=-1;
		rear=-1;
		return num;
	}
	else
	{
		num=cqueue[front];
		front=(front+1)%MAXSIZE;
		return num;
	}
}

void display()
{
	int i;
	if(front==-1)
	{
		printf("Queue is Empty");
	}
	else
	{
		printf("\nThe elements are: ");
		i=front;
		printf("%d\t",cqueue[i]);
		while(i!=rear)
		{
			i=(i+1)%MAXSIZE;
			printf("%d\t",cqueue[i]);
			
		}
	}
}

void main()
{
	int choice,num;
	char ch;
	do
	{
		printf("\n1. For Enqueue.");
		printf("\n2. For Dequeue.");
		printf("\n3. For Display.");
		printf("\n Enter your Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("\n Enter the number: ");
			scanf("%d",&num);
			enqueue(num);
			display();
			break;
			case 2: num=dequeue();
			if(num!=-999)
			{
				printf("\nThe number deleted is %d",num);
				display();
			}
			break;
			case 3: display();
			break;
			default: printf("\n Invalid Choice.");
		}
		printf("\n Do you want to continue ?");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');
}