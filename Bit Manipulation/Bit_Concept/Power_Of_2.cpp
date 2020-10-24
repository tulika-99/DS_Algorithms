/* in cpp*/
#include<iostream>
using namespace std;
int main()
{
    int n,count=0,temp;
    cout<<"enter the number ";
    cin>>n;
    temp=n;
    while(n)
    {
        if(n&1)
            count++;
        n=n>>1;
    }
    if(count==1)
        cout<<temp<<" is power of 2";
    else
        cout<<temp<<" is not power of 2";
    return 0;

}
