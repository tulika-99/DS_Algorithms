import java.util.Arrays;
import java.util.Scanner; 
  
class ExponentialSearch 
{ 
	//for positive values only
    // Returns position of first occurrence of 
    // x in array 
    static int exponentialSearch(int arr[], 
                                 int n, int x) 
    { 
        // If x is present at firt location itself 
        if (arr[0] == x) 
            return 0; 
      
        // Find range for binary search by 
        // repeated doubling 
        int i = 1; 
        while (i < n && arr[i] <= x) 
            i = i*2; 
      
        // Call binary search for the found range. 
        return Arrays.binarySearch(arr, i/2,  
                                   Math.min(i, n), x); 
    } 
    
    public static void display(int[] arr) {
    	for(int i=0;i<arr.length;i++) {
    		System.out.print(arr[i]+"\t");
    	}
    	System.out.println();
    }
    // Driver code 
    public static void main(String args[]) 
    { 
        int arr[] = {2, 3, 4, 10, 40};
        int choice,arrsize=0,number,check=0;
        int x = 10;
        int result = exponentialSearch(arr, arr.length, x); 
        
        display(arr);
        Scanner sc = new Scanner(System.in);
       
        while(true) {
        	
        	System.out.println("Input choice: ");
            System.out.println("1. Perform Exponential search");
            System.out.println("2. Create new array");
            System.out.println("3. Display array");
            System.out.println("4. Terminate Program");
            
            choice = sc.nextInt();
	        switch(choice) {
	        	case 1:
	        			System.out.print("Input search value: ");
	        			x=sc.nextInt();
	        			result=exponentialSearch(arr, arr.length, x);
	        			System.out.println((result < 0) ?  
	                        "Element is not present in array" : 
	                        "Element is present at index " +  
	                         result); 
	        			break;
	        	case 2:
	        		System.out.println("Input size of array: ");
	        		arrsize = sc.nextInt();
	        		arr=new int[arrsize];
	        		//inserting values in array
	        		for(int i=0;i<arrsize;i++) {
	        			System.out.println("Input value for index: "+ i);
	        			number = sc.nextInt();
	        			for(int j=0;j<i;j++) {
	        				if(arr[j]==number) {
        						check=1;//check 1(duplicate)
        					}
	    					
	       				}
	        			while(number<0||check==1) {
	        				if(number<0)
	        					System.out.println("Please input a positive integer");
	        				if(check==1) {
	        					System.out.println("Please input another value, duplicate found");
	        					System.out.println("Input value for index: "+ i);
	                			number = sc.nextInt();
	                			check=0;
		        				for(int j=0;j<i;j++) {
		        					if(arr[j]==number) {
		        						check=1;
		        					}
		        				}
	        				}
	        			}
	        			arr[i]=number;
	        			check=0;
	        		}
	        		
	        		Arrays.sort(arr);
	        			break;
	        	case 3:
	        			display(arr);
	        			break;
	        			
	        	case 4:
	        			System.exit(0);
	        			break;
	        	default: 
	        }
        }
        
    }
} 