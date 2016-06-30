#include <stdio.h>
void merge(int A[],int p,int q,int r)
{
    int i,j,k;
    int n1=q-p+1;
    int n2=r-q;
    //temp arrays
    int B[n1],C[n2];
    for(i=0;i<n1;i++)
        B[i]=A[p+i];
    for(j=0;j<n2;j++)
        C[j]=A[q+1+j];
    i=0;
    j=0;
    k=p;
    while(i<n1 && j<n2)
    {
        if(B[i]<=C[j])
        {
            A[k]=B[i];
            i++;
        }
        else 
        {
            A[k]=C[j];
            j++;
        }
        k++;
    }
    //Copy rem elements
    while(i<n1)
    {
        A[k]=B[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        A[k]=C[j];
        j++;
        k++;
    }
    
}
void mergesort(int A[],int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        mergesort(A,p,q);
        mergesort(A,q+1,r);
        merge(A,p,q,r);
    }
}
//prints array
void printarr(int A[],int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d ",A[i]);
    printf("\n");    
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printarr(arr, arr_size);
 
    mergesort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printarr(arr, arr_size);
    return 0;
}
