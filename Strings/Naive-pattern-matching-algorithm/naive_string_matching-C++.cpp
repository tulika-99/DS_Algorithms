/*
* Problem Statement: Given a text and a pattern, we have to check whether pattern occurs in text or not.
If it occurs, then print the starting position of the found pattern otherwise print 'Pattern not found'.
* Assumption: Position of characters in text start from 1 (1-based indexing)
* Given below is the implementation of the pattern searching algorithm using naive or brute force approach.
*/
#include<bits/stdc++.h>
using namespace std;
void patternMatching(string T, string P)
{
    int m = T.size();
    int n = P.size();
    for(int i = 0; i <= m-n; i++)
    {
        int j;
        for(j = 0; j < n; j++)
        {
            if(T[i+j] != P[j])
            {
                    break;
            }
        }
        if(j == n)
           {
              cout<<"Pattern found at "<<i+1;
              return;
           }
    }
    cout<<"Pattern not found";
}
int main()
{
    string T, P;
    cout<<"Enter the text : "<<endl;
     getline(std::cin, T);
    cout<<"Enter the pattern : "<<endl;
     getline(std::cin, P);

   patternMatching(T, P);

    return 0;
}
