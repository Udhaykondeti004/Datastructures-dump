#include<stdio.h>
#include<stdlib.h>


struct linkedlist
{
	int val;
	struct linkedlist *next;
};

typedef struct linkedlist NODE;

NODE *start;


void initializeList()
{
	NODE *ptr;
	int i=1,n;
	printf("\nEnter the number of elements: ");
	scanf("%d",&n);
	while(i<=n)
	{
		if(start==NULL)
		{
			start=(NODE *)malloc(sizeof(NODE));
			printf("\nEnter the value: ");
			scanf("%d",&start->val);
			start->next=NULL;
			ptr=start;
			i++;
		}
		else
		{
			ptr->next=(NODE *)malloc(sizeof(NODE));
			ptr=ptr->next;
			printf("\nEnter the value: ");
			scanf("%d",&ptr->val);
			ptr->next=NULL;
			i++;
		}
	}
}

void insertBeg()
{
	NODE *ptr;
	ptr=(NODE *)malloc(sizeof(NODE));
	printf("\nEnter the value: ");
	scanf("%d",&ptr->val);
	ptr->next=start;
	start=ptr;
}

void insertEnd()
{
	NODE *ptr;
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=(NODE *)malloc(sizeof(NODE));
	ptr=ptr->next;
	printf("\nEnter the value: ");
	scanf("%d",&ptr->val);
	ptr->next=NULL;
}

void insertSpecific()
{
	int i=1,loc;
	NODE *ptr,*temp;
	ptr=start;
	printf("\nEnter the location: ");
	scanf("%d",&loc);
	while(i<loc-1)
	{
		ptr=ptr->next;
		i++;
	}
	temp=(NODE *)malloc(sizeof(NODE));
	printf("\nEnter the value: ");
	scanf("%d",&temp->val);
	temp->next=ptr->next;
	ptr->next=temp;
}

void delFirst()
{
	NODE *ptr;
	ptr=start;
	start=start->next;
	free(ptr);
}

void delLast()
{
	NODE *ptr,*temp;
	ptr=start;
	while(ptr->next!=NULL)
	{
		temp=ptr;
		ptr=ptr->next;
	}
	temp->next=NULL;
	free(ptr);
}

void delSpecific()
{
	int i=1,loc;
	NODE *ptr,*temp;
	ptr=start;
	printf("\nEnter the location: ");
	scanf("%d",&loc);
	while(i<loc)
	{
		temp=ptr;
		ptr=ptr->next;
		i++;
	}
	temp->next=ptr->next;
	free(ptr);
}

void displayList()
{
	NODE *ptr;
	
	if(start==NULL)
	{
		printf("\nThe list is empty");
	}
	else
	{
		ptr=start;
		printf("\nThe elements of the list are: ");
		while(ptr!=NULL)
		{
			printf("%d\t",ptr->val);
			ptr=ptr->next;
		}		
	}
	
}

void main()
{
	int choice;
	char ch;
	initializeList();
	displayList();
	
	do
	{
		printf("\n1. For Insert at Beginning.");
		printf("\n2. For Insert at End.");
		printf("\n3. For Insert at Specific Location.");
		printf("\n4. For Deletion at Beginning.");
		printf("\n5. For Deletion at End.");
		printf("\n6. For Deletion at Specific.");
		printf("\n Enter your choice: ");
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
			case 4: delFirst();
					displayList();
					break;
			case 5: delLast();
					displayList();
					break;
			case 6: delSpecific();
					displayList();
					break;
			default: printf("\nInvalid Choice."); 
		}
		
	}
	
