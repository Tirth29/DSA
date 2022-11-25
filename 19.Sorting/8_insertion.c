#include <stdio.h>
#include <stdlib.h>

void swap()
{

}

void insertion(int a[],int n)
{
    int i,j,x;
    for(i=1;i<n;i++)
    {
        j=i-1;
        x=a[i];
        while(j>-1 && a[j]>x)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}
void print(int a[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int main()
{
    int a[]={11,14, 7, 12, 16, 9, 24, 5, 10, 17};
    insertion(a,10);
    print(a,10);
    return 0;

}