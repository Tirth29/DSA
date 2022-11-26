#include <stdio.h>

void merge(int a[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int b[20];
    while (i <= mid && j <= h)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    for (; i <=mid; i++)
        b[k++] = a[i];
    for (; j <=h; j++)
        b[k++] = a[j];
    for (i = l; i <=h; i++)
        a[i] = b[i];
}

void Rmerge(int a[],int l, int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        Rmerge(a,l,mid);
        Rmerge(a,mid+1,h);
        merge(a,l,mid,h);

    }
}

int main()
{
    int a[] = {11, 14, 7, 12, 16, 9, 24, 5, 10, 17};
    Rmerge(a,0,10);
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}