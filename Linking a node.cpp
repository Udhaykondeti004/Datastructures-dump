#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node *next;
};

int main()
{
	struct node *start = NULL; //created a node which is stored in start
	start = (struct node *)malloc(sizeof(struct node));
	start->val = 45;
	start->next = NULL;
	
	struct node *ptr;//created another node stored in ptr
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->val = 98;
	ptr->next = NULL;
	
	start->next = ptr; //address of ptr is stored in node, which is accessed using start
	return 0;
}

