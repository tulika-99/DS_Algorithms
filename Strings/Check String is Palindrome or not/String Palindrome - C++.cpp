/*To check whether a string is palindrom or not. 
We will use two pointer approach. One from starting and another one from ending.
If any mismatch occurs then string is not palindrome, else it is palindrome.*/

#include <iostream>
using namespace std;

bool IsPalindrome( string s ){
    int i = 0;
    int j = s.length()-1; 
    while(i<=j){
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    string s;
    cout<<"\n\tEnter a string : ";
    cin>>s;
    if(IsPalindrome(s))
        cout<<"\n\t\t"<<s<<" is palindrome";
    else
        cout<<"\n\t\t"<<s<<" is not palindrome";
    return 0;
}
