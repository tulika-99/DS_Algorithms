/***

Question :- Find the LCM of two numbers

LCM (Least Common Multiple) :- The smallest number which can be divided by both given numbers. 

In this problem user will give two numbers then we have to return the LCM of those numbers


Solution :- An efficient solution is based on the below formula for LCM of two numbers ‘a’ and ‘b’. 

a x b = LCM(a, b) * GCD (a, b)
LCM(a, b) = (a x b) / GCD(a, b)


***/


#include <iostream> 
using namespace std;
 
// Using recursion to return the gcd of a and b 
long long gcd(long long int a, long long int b){
  if (b == 0) return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers 
long long lcm(int a, int b){
    return (a / gcd(a, b)) * b;
}
  

int main(){ 
    int a = 20, b = 40; 
    cout <<"LCM of " << a << " and " << b << " is " << lcm(a, b); 
    return 0; 
} 
