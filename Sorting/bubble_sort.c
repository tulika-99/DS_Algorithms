#include<stdio.h>
int swap(int *arr1,int *arr2);
int bubble_sort(int arr[],int n);
int main()
{
    int N,i;
    scanf("%d",&N);
    int arr[N];
    for(i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    bubble_sort(arr,N);
    for(i=0;i<N;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
int swap(int *arr1,int *arr2)
{
    int temp = *arr2;
    *arr2 = *arr1;
    *arr1 = temp;
    return 0;
}
int bubble_sort(int arr[],int n)
{
    int i,j,swapped,N = n;
    for(i=0;i<n;i++)
    {
        swapped = 0;
        for(j=0;j<N-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                swapped = 1;
            }
        }
        if(swapped == 0)
        break;
    }
    return 0;
}
