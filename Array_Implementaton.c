
#include<stdio.h>
#include<conio.h>


void traverse(int a[],int n)
{
	int i;
	printf("\nThe elements of the array are: ");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}

void main()
{
	int a[20],n,num,i,loc,ch;
	char choice;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("\nEnter %d elements: ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	traverse(a,n);
	
	do
	{
		printf("\n 1. For insertion at beginning");
		printf("\n 2. For insertion at end");
		printf("\n 3. For insertion at specific location");
		printf("\n 4. For Deletion at Beginning.");
		printf("\n 5. For Deletion at End.");
		printf("\n 6. For Deletion at specific location.");
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n Enter the new element: ");
				scanf("%d",&num);
				for(i=n-1;i>=0;i--)
				{
					a[i+1]=a[i];
				}
				a[0]=num;
				n=n+1;
				traverse(a,n);
				break;
			case 2:
				printf("\n Enter the new element: ");
				scanf("%d",&num);
				a[n]=num;
				n=n+1;
				traverse(a,n);
				break;
			case 3:
				printf("\n Enter the location at which you want to insert: ");
				scanf("%d",&loc);
				printf("\n Enter the new element: ");
				scanf("%d",&num);
				for(i=n-1;i>=loc-1;i--)
				{
					a[i+1]=a[i];
				}
				a[loc-1]=num;
				n=n+1;
				traverse(a,n);
				break;
			case 4:
				for(i=0;i<n;i++)
				{
					a[i]=a[i+1];
				}
				n=n-1;
				traverse(a,n);
				break;
			case 5:
				n=n-1;
				traverse(a,n);
				break;
			case 6:
				printf("\n Enter the spcific location to delete.");
				scanf("%d",&loc);
				for(i=loc-1;i<n;i++)
				{
					a[i]=a[i+1];
				}
				n=n-1;
				traverse(a,n);
				break;
			default: printf("\n Enter correct choice.");
				
		}
		printf("\n Do you want to continue?");
		fflush(stdin);
		scanf("%c",&choice);
	}while(choice == 'y' || choice=='Y');
	
}
