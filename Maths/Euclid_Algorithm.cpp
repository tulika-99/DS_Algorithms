// Euclid Algorithm explains about calculating GCD of numbers
// GCD of two numbers is the largest number that divides both of them. A simple way to find GCD is to factorize both numbers and multiply common factors.
//Euclidean Algorithm
/* #include <iostream>
#include <string>

int gcd(int a, int b) 
{ 
    // Everything divides 0  
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
  
    // base case 
    if (a == b) 
        return a; 
  
    // a is greater 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
}

*/

//Actual implementation

// C++ program to demonstrate 
// Basic Euclidean Algorithm 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return 
// gcd of a and b 
int gcd(int a, int b) 
{ 
	if (a == 0) 
		return b; 
	return gcd(b % a, a); 
} 

// Driver Code 
int main() 
{ 
	int a = 10, b = 15; 
	cout << "GCD(" << a << ", "
		<< b << ") = " << gcd(a, b) 
						<< endl; 
	a = 35, b = 10; 
	cout << "GCD(" << a << ", "
		<< b << ") = " << gcd(a, b) 
						<< endl; 
	a = 31, b = 2; 
	cout << "GCD(" << a << ", "
		<< b << ") = " << gcd(a, b) 
						<< endl; 
	return 0; 
} 

// This code is contributed 
// by Nimit Garg 
