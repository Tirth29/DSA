#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void selection(int a[], int n)
{
    int i, j, k;
    for(i=0;i<n;i++)
    {
        for(j=k=i;j<n-1;j++)
        {
            if(a[j]<a[k])
                k=j;
        }
        swap(&a[i],&a[k]);
    }
}

int main()
{   
    int a[]={11,14, 7, 12, 16, 9, 24, 5, 10, 17};
    selection(a,10);
    for(int i=0; i<10; i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}