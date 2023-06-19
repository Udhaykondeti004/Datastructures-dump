#include <stdio.h>
int transverse(int*,int);
int main(void) {
	int a[5],i,b,*p;
	printf("Enter size of the array\n");
	scanf("%d",&b);
	printf("Enter %d elements\n",b);
	for(i=0;i<b;i++)
	    scanf("%d",&a[i]);
	    p = &a[0];
	    transverse(p,b);
	return 0;
}
int transverse(int *x,int y){
    int i,n;
    n = sizeof(i);
    printf("n=%d\n",n);
    for(i=0;i<y;i++)
    printf("%d  ",*(x+i));
}

