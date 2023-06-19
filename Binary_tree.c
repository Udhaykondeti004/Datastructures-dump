#include<stdio.h>
#include<stdlib.h>

struct btree
{
	struct btree *leftchild;
	struct btree *rightchild;
	int val;
};

typedef struct btree NODE;

NODE *root;


void buildSubTree(NODE *currentroot)
{
	char ch;
	NODE *left,*right;
	printf("\nWhether %d has a left child: ",currentroot->val);
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='y')
	{
		left=(NODE *)malloc(sizeof(NODE));
		currentroot->leftchild=left;
		printf("\nEnter the value for left child of %d: ",currentroot->val);
		scanf("%d",&left->val);
		buildSubTree(left);
	}
	else
	{
		currentroot->leftchild=NULL;
	}
	printf("\nWhether %d has a right child: ",currentroot->val);
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='y')
	{
		right=(NODE *)malloc(sizeof(NODE));
		currentroot->rightchild=right;
		printf("\nEnter the value for right child of %d : ",currentroot->val);
		scanf("%d",&right->val);
		buildSubTree(right);
	}
	else
	{
		currentroot->rightchild=NULL;
	}
}

void preOrderTraversal(NODE *ptr)
{
	if(ptr!=NULL)
	{
		printf("%d\t",ptr->val);
		preOrderTraversal(ptr->leftchild);
		preOrderTraversal(ptr->rightchild);
	}
}

void initializebtree()
{
	char ch;
	if(root==NULL)
	{
		root=(NODE *)malloc(sizeof(NODE));
		printf("\nEnter the value for root: ");
		scanf("%d",&root->val);
		root->leftchild=NULL;
		root->rightchild=NULL;
	}
	buildSubTree(root);
}

void main()
{
	initializebtree();
	printf("\n The preorder traversal of the tree: ");
	preOrderTraversal(root);
}