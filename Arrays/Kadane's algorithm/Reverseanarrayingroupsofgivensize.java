Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.

	
	 
Input: 
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9] 
k = 3 
Output: 
[3, 2, 1, 6, 5, 4, 9, 8, 7]

Input: 
arr = [1, 2, 3, 4, 5, 6, 7, 8] 
k = 5 
Output: 
[5, 4, 3, 2, 1, 8, 7, 6]

Input: 
arr = [1, 2, 3, 4, 5, 6] 
k = 1 
Output: 
[1, 2, 3, 4, 5, 6] 




// Java program to reverse every sub-array formed by
// consecutive k elements
class solution {
	
	// Function to reverse every sub-array formed by
	// consecutive k elements
	static void reverse(int arr[], int n, int k)
	{
		for (int i = 0; i < n; i += k)
		{
			int left = i;
	
			// to handle case when k is not multiple
			// of n
			int right = Math.min(i + k - 1, n - 1);
			int temp;
			
			// reverse the sub-array [left, right]
			while (left < right)
			{
				temp=arr[left];
				arr[left]=arr[right];
				arr[right]=temp;
				left+=1;
				right-=1;
			}
		}
	}
	
	// Driver method
	public static void main(String[] args)
	{
		
		int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
		int k = 3;
	
		int n = arr.length;
	
		reverse(arr, n, k);
	
		for (int i = 0; i < n; i++)
			System.out.print(arr[i] + " ");
	}
}


