#include<bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[],int n)
{
   for(int i=0;i<n;i++)
   {
      for(int j=1;j<n-i;j++)
      {
         if(arr[j-1]>arr[j])
            arr[j]=(arr[j]+arr[j-1])-(arr[j-1]=arr[j]);
      }
   }
}

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  bubbleSort(arr,n);
  for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}
