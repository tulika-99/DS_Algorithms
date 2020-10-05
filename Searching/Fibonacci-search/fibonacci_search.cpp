#include <bits/stdc++.h>

using namespace std;

int fibonacciSearch(int a[], int n, int key){
    int first = 0;
    int second = 1;
    int next = first + second;
    
    while(next < n){
        first = second;
        second = next;
        next = first + second;
    }
    
    int offset = -1; 
    
    while(next > 1){
        int val;
        val = min(offset+first, n-1);
        
        if(a[val] < key){
            next = second;
            second = first;
            first = next - second;
            offset = val;
        }
        else if(a[val] > key){
            next = first;
            second = second - first;
            first = next - second;
        }
        else return val;
        
    }
    
    if(second && a[offset + 1] == key) return offset+1;
    
    return -1;
    
}


int main()
{
    int n, i;
    cout << "\nEnter the size of array:";
    cin >> n;
    int a[n];
    cout << "\nEnter the elements of array:";
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    int key;
    cout << "\n enter the value to be searched:";
    cin >> key;
    cout << "\nFound at position:" << fibonacciSearch(a, n, key);

    return 0;
}
