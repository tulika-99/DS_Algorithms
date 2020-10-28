#include<bits/stdc++.h>
using namespace std;
 
// Function to get maximum value in array a[].
int getmax(int a[], int n)
{
  int max = a[0];
  for (int x=1; x<n; x++)
    if (a[x] > max)
      max = a[x];
  return max;
}
 
// Function to do counting sort according to significant digits repesented by
// exp (where exp is 10^i).
void CountSort(int a[], int n, int exp)
{  
  int result[n], i, count[10] = {0};
 
  // Counting occurence of digits
  for (i =0; i <n; i++)
    count[(a[i] / exp) % 10]++;
 
  // Changing the position of count so that it appears at actual position in result.
  for (i =1; i<10; i++)
    count[i] += count[i-1];
 
  // Resultant output array
  for (i =n-1; i>= 0; i--)
  {
    result[count[(a[i] / exp) % 10] - 1] = a[i];
    count[(a[i] / exp) % 10]--;
  }
  for (i =0; i <n; i++)
    a[i] = result[i];
}
 
// Radix Sort to sort a[] of given size.
void radixsort(int a[], int n)
{
  int exp, i;
  i = getmax(a, n);
  for (exp = 1; i/exp > 0; exp *= 10)
    CountSort(a, n, exp);
}

// Driver Program
int main()
{
  int n;
  cout<<" Enter the number of elements to be sorted: ";
  cin>>n;
    int a[n];
  
  cout<<"\n Enter the elements: ";
  for(int i =0; i <n; i++)
  {
    cin>>a[i];
  }
    radixsort(a, n);
 
  // Printing the sorted list.
  cout<<"\nSorted List: ";
  for (int i = 0; i < n; i++)
    cout<<a[i]<<", ";
  return 0;
}
