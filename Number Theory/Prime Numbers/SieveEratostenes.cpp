//This algorithm is used to find all prime numbers
//Time complexity is O(log(log(n)))

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=100000;
    int primeNumber[100000];
    for(int i=0;i<100000;i++)
        primeNumber[i]=1;

    primeNumber[0]=0;
    primeNumber[1]=0;

    for(int i=2;i<=sqrt(n);i++)
    {
        if(primeNumber[i]){
                for(int j=i*i ; j<=(n); j+=i)
                primeNumber[j]=0;

        }


    }
    for(int i=1;i<n;i++)
        if(primeNumber[i])
            cout<<i<<" ";

}
