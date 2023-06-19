#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node *next;
};

struct node *add_beg(struct node *start, int v)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->val = v;//assigning data
	ptr->next = NULL;
	
	ptr->next = start;//storing start address in ptr
	start = ptr;//storing ptr address in start(making it as first node)
	return start;	
}

int main()
{
	struct node *start = (struct node *)malloc(sizeof(struct node));
	start->val = 45;
	start->next = NULL;
	
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->val = 98;
	ptr->next = NULL;
	start->next = ptr; //storing second nodes adress in first node
	
	int val = 3;
	start = add_beg(start,val);
	
	ptr = start;//used to traverse linkedlist
	while(ptr!=NULL)
	{
		printf("%d ",ptr->val);
		ptr = ptr->next;
	}
	return 0;
}
