#include<bits/stdc++.h>
using namespace std;

//To check if kth bit in a binary representation of a number n is SET(1) or RESET(0)

//Left shift method
bool isSet1(int n, int k){
    if((1 << (k-1)) & n )
        return true;
    return false;
}
//Right shift method
bool isSet2(int n, int k){
    if((n >> (k-1)) & 1 )
        return true;
    return false;
}

int main(){
    cout<<isSet1(2,2)<<" "<<isSet2(2,2)<<endl;
    return 0;
}