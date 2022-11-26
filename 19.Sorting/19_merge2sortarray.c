#include <stdio.h>
#include <stdlib.h>

void mergesort(int a[], int b[], int m, int n)
{
    int i,j,k,c[20];
    i=j=k=0;
    while(i<m && j<n)
    {
        if(a[i]<b[j])
            c[k++]=a[i++];
        else    
            c[k++]=b[j++];
    }
    for(;i<m;i++)
        c[k++]=a[i++];
    for(;j<n;j++)
        c[k++]=b[j++];

    for(int i=0;i<m+n;i++)
        printf("%d ",c[i]);
}

int main()
{   
    int a[]={1,3,5,7,9},b[]={2,4,6,8,10};
    mergesort(a,b,5,5);
    return 0;
}