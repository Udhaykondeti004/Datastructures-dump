#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node *next;
};

int main()
{
	struct node *start = NULL;//created a node which is stored in start
	start = (struct node *)malloc(sizeof(struct node));
	start->val = 45;
	start->next = NULL;
	
	struct node *ptr = NULL;//created another node stored in ptr
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->val = 98;
	ptr->next = NULL;
	start->next = ptr;
	
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = 3;
	ptr->next = NULL;
	
	start->next->next = ptr; //using single pointer for many nodes
	
	return 0;
}
