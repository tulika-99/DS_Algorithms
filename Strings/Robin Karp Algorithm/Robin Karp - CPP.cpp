/***

Rabin-Karp is a pattern searching algorithm to find the pattern in a efficient way. It checks the pattern by moving window one by one, but without checking
all characters for all cases, it finds the hash value. When the hash value is matched, then only it tries to check each character. It uses hash functions 
and the rolling hash technique. A hash function is essentially a function that maps one thing to a value. A rolling hash allows an algorithm to calculate 
a hash value without having to rehash the entire string.

Limitations of Rabin-Karp Algorithm
Spurious Hit
When the hash value of the pattern matches with the hash value of a window of
the text but the window is not the actual pattern then it is called a spurious
hit.
Spurious hit increases the time complexity of the algorithm. In order to
minimize spurious hit, we use modulus. It greatly reduces the spurious hit.

***/

// Time Complexity (Best & Average Time) = O(N+M), Worst Case = O(N*M)


#include<iostream>
#include<string.h>
using namespace std;
 
// Number of characters in the input alphabet 
#define numOfChar 256 

void search(char pat[], char txt[], int q){ 
    int patLen = strlen(pat), txtLen = strlen(txt); 
    int itr1, itr2, c = 1; 
    int a = 0; // hash value for pattern 
    int b = 0; // hash value for txt     
 
    // The value of c would be "pow(numOfChar, M-1)%q" 
    for (itr1 = 0; itr1 < patLen - 1; itr1++) 
        c = (c * numOfChar) % q; 
 
    // Calculate the hash value of pattern and first window of text  
    for (itr1 = 0; itr1 < patLen; itr1++){ 
        a = (numOfChar * a + pat[itr1]) % q; 
        b = (numOfChar * b + txt[itr1]) % q; 
    } 
 
    // Slide the pattern over text one by one 
    for (itr1 = 0; itr1 <= txtLen - patLen; itr1++){ 
 
        // Check the hash values of current window of text and pattern. If the hash values match then only check for characters on by one 
        if ( a == b ){ 
			// Check for characters one by one 
            for (itr2 = 0; itr2 < patLen; itr2++){ 
                if (txt[itr1+itr2] != pat[itr2]) break;                     
            } 
 
            // if a == b and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            if (itr2 == patLen)  cout << "Pattern found at index " << itr1 << endl;                
        } 
 
        // Calculate hash value for next window of text: Remove leading digit, add trailing digit         
        if ( itr1 < txtLen-patLen ){ 
            b = (numOfChar*(b - txt[itr1]*c) + txt[itr1+patLen])%q; 
 
            // if b might have negative value then we will convert it into the positive 
            if (b < 0) b = (b + q); 
        } 
    } 
} 
 
int main(){ 
    char txt[] = "GEEKS FOR GEEKS"; 
    char pat[] = "GEEK";
       
    // A prime number 
    int q = 101; 
     
    // Function Calling
    search(pat, txt, q); 
    return 0; 
} 
