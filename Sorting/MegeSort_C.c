//Merge sort is divide and Conquer algorithm
//Time complexity : O(nlogn)

#include<stdio.h>
void Merge(int a[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;

    int left[n1],right[n2];

    for(int i=0;i<n1;i++)
        left[i]=a[i+l];

    for(int i=0;i<n2;i++)
        right[i]=a[mid+i+1];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
            {
                a[k]=left[i];
                i++;
            }
        else
        {
            a[k]=right[j];
            j++;
        }
        k++;

    }

    while(i<n1)
    {
        a[k]=left[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        a[k]=right[j];
        j++;
        k++;
    }

}


void mergeSort(int a[],int l,int r)
{
    if(l<r)
    {
        int mid=l+(r-l)/2;

        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);

        Merge(a,l,mid,r);
    }
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
    mergeSort(a,0,n-1);
     printf("Array After Sorting \n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

}

