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
void insertAfterSpecificValue()
{
int i=1,value;
NODE *ptr,*temp;
ptr=start;
printf("\nEnter the specific value: ");
scanf("%d",&value);
while(ptr->val!=value)
{
ptr=ptr->next;
}
temp=(NODE *)malloc(sizeof(NODE));
printf("\nEnter the value: ");
scanf("%d",&temp->val);
temp->next=ptr->next;
ptr->next=temp;
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
int main() {
    int choice;
    char ch;
    initializeList();
    displayList();


insertAfterSpecificValue();
displayList();

   
   
    return 0;
}