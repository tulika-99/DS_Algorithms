#include<stdio.h>
int swap(int *arr1,int *arr2);
int selection_sort(int arr[],int n);
int main()
{
    int N,i;
    scanf("%d",&N);
    int arr[N];
    for(i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    selection_sort(arr,N);
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

int selection_sort(int arr[],int n)
{
    int i,j,min;
    for(i=0;i<n;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
            min = j;
        }
        swap(&arr[i],&arr[min]);
    }
    return 0;
}
