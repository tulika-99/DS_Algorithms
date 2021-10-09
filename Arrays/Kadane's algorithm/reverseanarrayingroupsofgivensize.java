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


