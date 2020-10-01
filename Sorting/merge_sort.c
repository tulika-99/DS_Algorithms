#include<stdio.h>
void merge_array(int arr[],int l,int m,int r);
int merge_sort(int arr[],int l,int r);
int main()
{
    int N,i;
    scanf("%d",&N);
    int arr[N];
    for(i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,N-1);
    for(i=0;i<N;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

void merge_array(int arr[],int l,int m,int r)
{
    int i,j,k;
    int n1 = m - l +1;
    int n2 = r - m;

/*To create temporary arrays*/
	int L[n1],R[n2];

/* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

/* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray

      while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

/* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

/* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
int merge_sort(int arr[],int l,int r)
{
    if(r>l)
    {
       int m = l + (r - l)/2;
       merge_sort(arr,l,m);
       merge_sort(arr,m+1,r);
       merge_array(arr,l,m,r);
    }
    return 0;
}
