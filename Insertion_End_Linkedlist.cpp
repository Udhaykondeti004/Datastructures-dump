#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node *next;
};

void insert_end(struct node *start,int val)
{
	struct node *ptr,*temp;
	ptr = start;//used for traversing
	temp = (struct node *)malloc(sizeof(struct node));
	temp->val = val;
	temp->next = NULL;
	
	while(ptr->next!=NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = temp;
}

int main()
{
	struct node *start = (struct node *)malloc(sizeof(struct node));
	start->val = 45;
	start->next = NULL;

	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->val = 98;
	ptr->next = NULL;
	start->next = ptr;
	
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->val = 3;
	p->next = NULL;
	start->next->next = p;
	
	int val = 67;
	insert_end(start,val);
	
	ptr = start;//used to traverse linkedlist
	while(ptr!=NULL)
	{
		printf("%d ",ptr->val);
		ptr = ptr->next;
	}
	return 0;
	
}

