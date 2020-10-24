/*
   Minimum Count
   Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
   That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. 
   The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
   
 */
 
#include<bits/stdc++.h>
using namespace std;

int minCount(int n)
{
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=4;i<=n;i++)
    {
        dp[i]=i;
        for(int x=1;x<=i;x++)
        {
            int temp=x*x;
            
            if(temp>i)
                break;
            else{
            dp[i]=min(dp[i],1+dp[i-temp]);
                
            }
        }
    }
    return dp[n];  
     
    
}

// Driver code

int main(){
    int n;
    cin>>n;
    cout<<minCount(n);
}
