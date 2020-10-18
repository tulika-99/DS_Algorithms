#include<bits/stdc++.h>
using namespace std;

// Gold mine problem using dynamic programming for calculating maximum gold that can be collected 
// allowed moves in the 2-D grid are right, right-down, right-up
int goldMine(vector<vector<int>> a, int m, int n) 
{ 
    vector<vector<int>> dp(m,vector<int>(n));
    int ma=0;
  
    for (int i=n-1; i>=0; i--) 
    { 
        for (int j=0; j<m; j++) 
        { 
            dp[j][i]=a[j][i];
            
            // for moving right side
            if(i!=n-1)
            {
                ma=max(ma,dp[j][i+1]);
            } 
            // for moving right-down side
            if(j!=m-1 && i!=n-1)
            {
                ma=max(ma,a[j+1][i+1]);
            }
            // for moving right-up side
            if(j && i!=n-1)
            {
                ma=max(ma,dp[j-1][i+1]);
            }
            dp[j][i] = a[j][i]+ma; 
        } 
    } 
   
    int ans = dp[0][0]; 
    for (int i=1; i<m; i++) 
        ans = max(ans, dp[i][0]); 
    
    return ans; 
} 

int main()
{
    int m,n; // dimensions of 2-D grid
    cin>>m>>n;
    
    vector<vector<int>> a(m,vector<int> (n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<goldMine(a,m,n);
    
    return 0;
}