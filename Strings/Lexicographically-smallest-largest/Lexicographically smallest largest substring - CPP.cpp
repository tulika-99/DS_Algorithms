/*

Question :- Given String str and an integer k, find the lexicographically smallest and largest substring of length k

Solution :- We initialize max and min as first substring of size k. We traverse remaining substrings, by removing first character of previous substring
and adding last character of new string. We keep track of the lexicographically largest and smallest.

*/
 
#include<iostream>  
using namespace std; 
  
void getSmallestAndLargest(string str, int k) 
{       
    // Initializing min and max as first substring of size k
    string currStr = str.substr(0, k); 
    string lexMin = currStr; 
    string lexMax = currStr; 

    // Consider all remaining substrings. We consider every substring ending with index i. 
    for (int itr = k; itr < str.length(); itr++){ 
        currStr = currStr.substr(1, k) + str[itr]; 
        if (lexMax < currStr) lexMax = currStr; 
        if (lexMin >currStr) lexMin = currStr;      
    } 

    // Printing result 
    cout << lexMin << endl; 
    cout << lexMax << endl; 
} 


int main(){ 
    string str = "AkashSahu"; 
    int k = 3; 
    getSmallestAndLargest(str, k); 
} 

