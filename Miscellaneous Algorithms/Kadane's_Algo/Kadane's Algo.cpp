#include<bits/stdc++.h>

using namespace std;

int Kadane(int arr[],int n)
{
    int max_sum=0,curr_sum=0;
    for(int i=0;i<n;i++)
    {
        curr_sum=max(curr_sum+arr[i],arr[i]);
        if(curr_sum<0)
        curr_sum=0;
        
        max_sum=max(max_sum,curr_sum);
    }
    return max_sum;
}

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  cout<<Kadane(arr,n)<<"\n";
}
