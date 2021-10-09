#include<bits/stdc++.h>
using namespace std;

int stob(string &s){
    int len = s.length();
    int decimal = 0;
    int base = 1;
    for(int i=len-1; i>=0; i--){
        if(s[i] == '1')
            decimal += base;
        base *= 2;
    }
    return decimal;
}
int main(){
    string s = "101";
    cout<<stob(s)<<endl;
    return 0;
}