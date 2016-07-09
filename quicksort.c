#include <stdio.h>

void swap(int *a,int *b)
{
    
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int ar[],int l,int h)
{
    //last element as pivot
    int pivot=ar[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++)
    {
        if(ar[j]<=pivot)
        {
            i++;
            swap(&ar[i],&ar[j]);
        }
    }
     swap(&ar[i+1],&ar[h]);
     return (i+1);
}
void quicksort(int ar[],int l,int h)
{
    if(l<h)
    {
        int p=partition(ar,l,h);
        quicksort(ar,l,p-1);
        quicksort(ar,p+1,h);
    }
}
void printar(int ar[],int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", ar[i]);
    printf("\n");
}
int main()
{
    int ar[]={10, 7, 8, 9, 1, 5};
    int n=sizeof(ar)/sizeof(ar[0]);
    quicksort(ar,0,n-1);
    printf("Sorted array: \n");
    printar(ar,n);
    
    return 0;
}
