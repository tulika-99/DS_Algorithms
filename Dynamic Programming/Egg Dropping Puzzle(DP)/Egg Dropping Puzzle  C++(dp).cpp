#include<bits/stdc++.h>
using namespace std;
int static dp[51][51];
int solve(int e,int f)
{
    if(e==1)
        return f;
    if(f==0||f==1)
        return f;
    if(dp[e][f]!=-1)
        return dp[e][f];
    int minimum=INT_MAX;
    for(int k=1;k<=f;k++)
    {
        //max due to worst case
        int tempans=1+max(solve(e-1,k-1),solve(e,f-k));
        //minimum attempts
        minimum=min(minimum,tempans);
    }
    return dp[e][f]=minimum;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int e,f;
        cin>>e>>f;
        memset(dp,-1,sizeof(dp));
        cout<<solve(e,f)<<endl;
    }
	//code
	return 0;
}
