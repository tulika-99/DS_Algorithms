/*
* Longest Common Subsequence Problem Statement: Given two sequences, find the length of longest 
subsequence present in both of them. 
* A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 
* Given below is the implementation of the solution to this problem using Dynamic Programming approach.
*/
#include<iostream>
#include<cstring>
using namespace std;

int LCS(char* a,char* b,int m,int n)
{
	int S[11][11];
	int i,j;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0 || j==0)
			{
				S[i][j]=0;
			}
			else if(a[i-1]==b[j-1])
			{
				S[i][j]= S[i-1][j-1] + 1;
			}
			else
			{
				S[i][j]= max(S[i-1][j],S[i][j-1]);
			}
		}
	}
return S[m][n];
}
int main()
{
	char A[30],B[30];
	cout<<"Enter the string 1 : ";
	cin>>A;
	cout<<"\nEnter the string 2 : ";
	cin>>B;
	int m=strlen(A);
	int n=strlen(B);
	int l= LCS(A,B,m,n);
	cout<<"\nLength of longest common subsequence : "<<l;
	return 0;
}
