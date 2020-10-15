#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;
 
int randomPartition(int arr[], int l, int r);
 
int kthSmallest(int arr[], int l, int r, int k)
{
    
    if (k > 0 && k <= r - l + 1)
    {
        // find a position for random partition
        int pos = randomPartition(arr, l, r);
        
        // if this pos gives the kth smallest element, then return
        if (pos-l == k-1)
            return arr[pos];
            
        // else recurse for the left and right half accordingly
        if (pos-l > k-1)  
            return kthSmallest(arr, l, pos-1, k);
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }

    return INT_MAX;
}
 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// partitioning the array along the pivot
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

// finding the pivot element and partition the array along that
int randomPartition(int arr[], int l, int r)
{
    int n = r-l+1;
    int pivot = rand() % n;
    swap(&arr[l + pivot], &arr[r]);
    return partition(arr, l, r);
}
 
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
    int number_of_elements;
    cin>>number_of_elements;
    int a[number_of_elements];
    for(int i=0;i<number_of_elements;i++)
    {
    cin>>a[i];
    }
    int k;
    cin>>k;
    cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
