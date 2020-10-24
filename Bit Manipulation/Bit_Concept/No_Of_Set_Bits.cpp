/// no of set bits in a number in cpp
/* This is basically to count the no of set bit(1) in binary representation of the number */
#include<iostream>
using namespace std;
int main()
{
    int n,count=0,temp;
    cout<<"enter the number ";
    cin>>n;
    /* the idea is if the 0th bit is set then taking and bitwise and with 1 will give 1. to count all set bits we
    take bitwise right shift until the number become 0 */
    temp=n;
    while(n)
    {
        if(n&1)
            count++;
        n=n>>1;
    }
    cout<<"No of set bits in "<<temp<<" is :"<<count<<endl;
    return 0;
}
