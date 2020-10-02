#include<bits/stdc++.h>
using namespace std;
/*standard declarations*/
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<pair<ll,ll> > vllp; 
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frr(i,a,b) for(ll i=a;i>=b;i--)
#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define err() cout<<"=================================="<<endl;
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define all(A)  A.begin(),A.end()
#define allr(A)    A.rbegin(),A.rend()
#define ft first
#define sd second
#define pb push_back

/*global variables here*/

#define mxn 2000001
#define PI 3.14159265	
#define mod 1000000007	
ll TESTTEST;
string manstr;
ll arr[mxn];
/*global functions here*/	



void manachers(string str){
// It gives the jump length to do for getting palindrom 
//eg . str= "a"   
//output will be 0 0 1 0 0 
//and the 1 s for the index which have 'a' as character 
//thus manachers.substr(index-value+1,index+value-1) is the palindrome we are taking about.	

    manstr+="$#";
    fr(i,0,str.size()){
        manstr+=(str[i]);
        manstr+="#";
    }
    manstr+="@";
    ll C=0,R=0;
    fr(i,1,manstr.size()-1){
        ll mirr=2*C-i;
        
        if(i<R){ // finding the max palindrome end possible for current i 
            arr[i]=min(R-i,arr[mirr]);
        }
        
        while(manstr[i+(1+arr[i])]==manstr[i-(1+arr[i])]){ // finding whether u can extend  more to right or not 
            arr[i]++;
        }
        
        if(i+arr[i]>R){ // updating the boundary lines
            C=i;
            R=i+arr[i];
        }
        cout<<manstr[i]<<"  "<<arr[i]<<"  "<<C<<"  "<<R<<"\n";
    }
}
/*main function here*/							
void solve(){
    string str;
    cin>>str;
    manachers(str);
    fr(i,0,manstr.size()){
        cout<<arr[i]<<" ";
    }
}						
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll zzz=1;
	cin>>zzz;
	for(TESTTEST=1;TESTTEST<(zzz+1);TESTTEST++){
		solve();
	}
	return 0;
}