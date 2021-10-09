// C++ code for Max
// Container-with-most-water

#include<iostream>
using namespace std;
int maxArea(int A[], int len)
{
	int l = 0;
	int r = len -1;
	int area = 0;
	
	while (l < r)
	{
		// Calculating the max area
		area = max(area, min(A[l],A[r]) * (r - l));
						
			if (A[l] < A[r])
				l += 1;
				
			else
				r -= 1;
	}
	return area;
}

void takeinput(int arr[],int s)
{
    for(int i=0;i<s;i++)
     {
         cin>>arr[i];
     }
}

// Driver code
int main()
{
    
    // Variables used
     int s1,s2;
    
    // Input 1
     cout<<"Enter inputs size of 1st Array : ";
     cin>>s1;
     int a[s1];
     cout<<"\nEnter inputs size for 1st Array : ";
     takeinput(a,s1);
    
    // Input 2
    
    cout<<"\nEnter inputs size of 2nd Array : ";
    cin>>s2;
    int b[s2];
    cout<<"\nEnter inputs size for 2nd Array : ";
    takeinput(b,s2);
    
    // Answer
    cout<<"\nAnswer\n";
	int len1 = sizeof(a) / sizeof(a[0]);
	cout << maxArea(a, len1);
	
	int len2 = sizeof(b) / sizeof(b[0]);
	cout << endl << maxArea(b, len2);
}

