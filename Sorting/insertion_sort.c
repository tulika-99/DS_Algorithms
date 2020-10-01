#include<stdio.h>
int swap(int *arr1,int *arr2);
int insertion_sort(int arr[],int n);
int main()
{
    int N,i;
    scanf("%d",&N);
    int arr[N];
    for(i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    insertion_sort(arr,N);
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
int insertion_sort(int arr[],int n)
{
    int i,j,key;
    for(i=0;i<n;i++)
    {
        key = arr[i];
        j = i-1;
        while((j>=0)&&key<arr[j])
        {
            swap(&arr[j+1],&arr[j]);
            j--;
        }
        arr[j+1] = key;
    }
    return 0;
}
