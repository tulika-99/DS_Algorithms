//Matrix vhain multiplication by storing the values in An array
#include<bits/stdc++.h>
using namespace std;
int An[4][4]={0};
int mcm(int R[],int i,int j)
{
	int a,b,c=INT_MAX,k;
	if(i==j)
	return 0;
	if(An[i][j]==0)
	{
		for(k=i;k<j;k++)
		{
			int d=mcm(R,i,k);
			d+=mcm(R,(k+1),j);
			d+=(R[i-1]*R[j]*R[k]);
			if(d<c)
			c=d;	
		}
		An[i][j]=c;
	}
	return An[i][j];
}
int main()
{
	int i,n,j;
	cin>>n;
	int R[n+1];
	//int An[n][n]={0};
	for(i=0;i<=n;i++)
	{
		cin>>R[i];
	}
	i=mcm(R,1,4);
	cout<<i<<endl;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		cout<<An[i][j]<<" ";
		cout<<endl;
	}
}
