#include<stdio.h>
#include<stdlib.h>
void delete(int n,int *ptr,int loc);
int main()
{
int *ptr,n,i,loc;
scanf(“%d”,&n);//No. of elements
a=(int*)malloc(sizeof(int)*n);//Allocation using malloc
for(i=0;i<n;i++)
{
scanf(“%d”,(ptr+i));
}
scanf(“%d”,&loc);//Assigning Values
delete(n,ptr,loc);
return 0;
}
void delete(int n,int *ptr,int loc)
{
int i;
if(loc<=n)
{
for(i=loc-1;i<n;i++)
{
*(ptr+i)=*(ptr+i+1);//Deletion
}
printf(“Array after deletion is:\n”);
for(i=0;i<n-1;i++)
{
printf(“%d\n”,(*(ptr+i)));//Dispay
}
}
else
{
printf(“Invalid Input”);
}
}
