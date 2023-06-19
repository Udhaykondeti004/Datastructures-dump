#include<stdio.h>
#include<stdlib.h>

struct doublylinkedlist
{
	int val;
	struct doublylinkedlist *next;
	struct doublylinkedlist *prev;
};

typedef struct doublylinkedlist NODE;

NODE *start, *last;


void initializeList()
{
	char ch;
	do
	{
		if(start==NULL)
		{
			start=(NODE *)malloc(sizeof(NODE));
			printf("\nEnter the value: ");
			scanf("%d",&start->val);
			start->next=NULL;
			start->prev=NULL;
			last=start;
		}
		else
		{
			last->next=(NODE *)malloc(sizeof(NODE));
			last->next->prev=last;
			last=last->next;
			printf("\nEnter the value: ");
			scanf("%d",&last->val);
			last->next=NULL;
		}
		printf("\n Do you want to continue: ");
		fflush(stdin);
		scanf("%c",&ch);
		
	}while(ch=='y' || ch=='Y');
}

void insertBeg()
{
	NODE *ptr;
	if(start!=NULL)
	{
		ptr=(NODE *)malloc(sizeof(NODE));
		printf("\nEnter the value: ");
		scanf("%d",&ptr->val);
		ptr->next=start;
		start->prev=ptr;
		ptr->prev=NULL;
		start=ptr;
	}
	else
	{
		start=(NODE *)malloc(sizeof(NODE));
		printf("\nEnter the value: ");
		scanf("%d",&start->val);
		start->next=NULL;
		start->prev=NULL;
		last=start;
	}
}

void insertEnd()
{
	NODE *ptr;
	if(last!=NULL)
	{
		ptr=(NODE *)malloc(sizeof(NODE));
		printf("\n Enter the value: ");
		scanf("%d",&ptr->val);
		last->next=ptr;
		ptr->prev=last;
		ptr->next=NULL;
		last=ptr;
	}
	else
	{
		start=(NODE *)malloc(sizeof(NODE));
		printf("\nEnter the value: ");
		scanf("%d",&start->val);
		start->next=NULL;
		start->prev=NULL;
		last=start;
		
	}
}

void insertSpecific()
{
	NODE *ptr,*temp;
	int loc,i=1;
	if(start==NULL)
	{
		printf("\nList is empty.");
	}
	else
	{
		printf("\nEnter the location: ");
		scanf("%d",&loc);
		ptr=start;
		while(i<loc-1)
		{
			ptr=ptr->next;
			i++;
		}
		temp=(NODE *)malloc(sizeof(NODE));
		printf("\nEnter the value: ");
		scanf("%d",&temp->val);
		temp->next=ptr->next;
		ptr->next->prev=temp;
		ptr->next=temp;
		temp->prev=ptr;
	}
}

void deleteBeg()
{
	NODE *ptr;
	int num;
	if(start==NULL)
	{
		printf("\nList is empty.");
	}
	else
	{
		ptr=start;
		num=start->val;
		start=start->next;
		start->prev=NULL;
		free(ptr);
		printf("\n%d is deleted.",num);
	}
}

void deleteEnd()
{
	int num;
	NODE *ptr;
	if(last==NULL)
	{
		printf("\nList is empty.");
	}
	else
	{
		ptr=last;
		num=last->val;
		last=last->prev;
		last->next=NULL;
		free(ptr);
		printf("\n%d deleted.",num);
	}
}

void deleteSpecific()
{
	NODE *ptr,*temp;
	int loc,i=1,num;
	if(start==NULL)
	{
		printf("\nThe list is empty.");
	}
	else
	{
		ptr=start;
		printf("\nEnter the location: ");
		scanf("%d",&loc);
		while(i<loc-1)
		{
			ptr=ptr->next;
			i++;
		}
		temp=ptr->next;
		ptr->next=temp->next;
		temp->next->prev=ptr;
		num=temp->val;
		free(temp);
		printf("\n%d is deleted.",num);
	}
}

void displayList()
{
	NODE *ptr;
	ptr=start;
	printf("\nThe elements are: ");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->val);
		ptr=ptr->next;
	}
	
}


void main()
{
	char ch;
	int choice;
	initializeList();
	displayList();
	do
	{
		printf("\n1. Insert at Beginning.");
		printf("\n2. Insert at End.");
		printf("\n3. Insert at Specific Location");
		printf("\n4. Delete at Beginning.");
		printf("\n5. Delete at End.");
		printf("\n6. Delete at Specific Location");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insertBeg();
					displayList();
					break;
			case 2: insertEnd();
					displayList();
					break;
			case 3: insertSpecific();
					displayList();
					break;
			case 4: deleteBeg();
					displayList();
					break;
			case 5: deleteEnd();
					displayList();
					break;
			case 6: deleteSpecific();
					displayList();
					break;
			default: printf("\nInvalid Choice");
		}
		printf("\nDo you want to continue: ");
		fflush(stdin);
		scanf("%c",&ch);
		
	}while(ch=='y' || ch=='Y');
}
