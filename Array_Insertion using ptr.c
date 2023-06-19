#include<stdio.h>
#include<stdlib.h>
void insert(int n, int *ptr, int loc, int num)
{
int i;
printf(“Array after insertion is:\n”);
for(i=0;i<loc-1;i++)
{
printf(“%d\n”,*(ptr+i));//insertion
}
printf(“%d\n”,num);
for(i=loc-1;i<n;i++)
{
printf(“%d\n”,*(ptr+i));//display
}
}

int main()
{
int *ptr,n,i,loc,num;
scanf(“%d”,&n);//No.of elements
a=(int*)malloc(n*sizeof(int));//Allocation using malloc
for(i=0;i<n;i++)
{
scanf(“%d”,ptr+i);
}
scanf(“%d”,&loc);
if(loc<=n)
{
scanf(“%d”,&num);//Assigning Values
insert(n,ptr,loc,num);
}
else
{
printf(“Invalid Input”);
}
return 0;
}
     