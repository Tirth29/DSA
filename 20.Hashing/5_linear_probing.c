// #include <iostream>
#include <stdio.h>
#define size 10
// #include "chains.h"

int probe(int h[],int key)
{
    int index=hash(key);
    int i=0;
    while(h[(index+i)%size]!=0)
        i++;
    return (index+i)%size;
}

int hash(int key)
{
    return key%10;
}

void insert(int h[],int key)
{
    int index=hash(key);
    if(h[index]!=0)
        index=probe(h,key);
    h[index]=key;
}

int search(int h[],int key)
{
    int index=hash(key);
    int i=0;
    while(h[(index+i)%size]!=key)
        i++;
    return (index+i)%size;
}

int main()
{
    int ht[10]={0};
    // struct node *temp;
    int i;
    insert(ht,12);
    insert(ht,22);
    insert(ht,32);
    // temp=search(ht[hash(22)],22);
    // cout << temp->data << endl;
    printf("/nKey found at %d\n",search(ht,12));
    return 0;
}

