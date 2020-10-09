//A modular multiplicative inverse of an integer a is an integer x such that
// a.x is congruent to 1 modular some modulus m. To write it in a formal way:
//we want to find an integer x so that
//  a⋅x≡1 mod m.
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void EEA(ll a,ll b,ll& x,ll& y)
{

    if(a==1)
    {
        x=1;
        y=0;
        return;
    }

    ll x1,y1;
    EEA(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
}
ll modInverse(ll a,ll m)
{

    if(__gcd(a,m)!=1)
    {
        return -1;
    }
    ll x,y;
    EEA(a,m,x,y);
    x=(x%m+m)%m;
    return x;
}
int main()
{

    ll t;
    cin>>t;
    while(t--)
    {

        ll a,m,x;
        cin>>a>>m;
        x=modInverse(a,m);
        cout<<x<<" ";

        if(x!=-1)
            cout<<(x*a)%m;// To check whether modulo inverse is correct or not
        cout<<"\n";
    }
}
