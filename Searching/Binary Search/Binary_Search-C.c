// #include <stdio.h>

// int binary(int a[], int n, int call, int first, int last, int middle)
// {
//     first = 0;
//     last = n - 1;
//     middle = (first + last) / 2;
//     while (first <= last)
//     {
//         if (a[middle] < call)
//             first = middle + 1;
//         else if (a[middle] == call)
//         {
//             printf("Element %d is found at location %d  \n", call, (middle + 1));
//             break;
//         }
//         else
//             last = middle - 1;
//         middle = (first + last) / 2;
//     }
//     if (first > last)
//         printf("%d is not present in the array \n", call);
// }

// int main()
// {
//     int a[100], n, i, call, first, last, middle;
//     printf("Binary search is executed\n\n");
//     printf("Enter the number of elements you wish to enter\n");
//     scanf("%d", &n); //Elements should be sorted
//     printf("Enter the elements in a sorted order for binary search\n\n");
//     for (i = 0; i < n; i++) //Scanning Elements
//     {
//         scanf("%d", &a[i]);
//     }
//     printf("Enter the element to search\n");
//     scanf("%d", &call);                      //Search element
//     binary(a, n, call, first, last, middle); //Call to function
//     return 0;
// }

//another method
#include <iostream>
using namespace std;

     int binarySearch(int a[],int n,int key){
           int s=0,mid,e = n-1;
                
            while(s<=e){
                mid = (s+e)/2;
                 if(a[mid] == key){
                     return mid;
                     break;
                 }
                  else if(a[mid]>key){
                      e = mid-1;
                  }
                  else{
                      s = mid+1;
                  }
            }
            return -1;
     }

int main() {
    int n;
    cin>>n;
     int a[1024];
     for(int i=0;i<n;i++){
         cin>>a[i];
     }
       int key;
       cin>>key;
        cout<<binarySearch(a,n,key);
             
    return 0;
}

