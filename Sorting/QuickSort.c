//Quick Sort is based on divide and Conquer algorithm
//Time complexity : O(nlogn)

#include<stdio.h>

int swap(int * a,int *b)
{

    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int partition(int *a,int l,int r)
{
    int i=l-1;
    int pivot=a[r];

    for(int j=l;j<=r-1;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(&a[j],&a[i]);
        }

    }
    swap(&a[i+1],&a[r]);
    return i+1;

}

void quickSort(int a[],int l,int r)
{
    if(l>=r)
        return ;

    int pivot=partition(a,l,r);

    quickSort(a,l,pivot-1);
    quickSort(a,pivot+1,r);

}

int main()
{

    int n;
    printf("Enter Size of array \n");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements into array \n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    quickSort(a,0,n-1);
    printf("Array After Sorting \n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}

