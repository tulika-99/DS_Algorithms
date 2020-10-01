public class Search { 

    public static void main(String [] args) throws Exception {
        Search ob = new Search();
        int result;
        int[] arr = {2, 5, 6, 9, 13};

        result = ob.binarySearch(arr, 13);

        System.out.println(result);

    }

    //Binary Search function returns location of number in array or -1 if not found
    public int binarySearch(int[] arr, int num) {
        int left = 0, right = arr.length - 1;
        int mid = 0;

        while(left < right) {
            mid = (left + right)/2;

            if(arr[mid] == num)
                return mid;
            if(arr[mid] < num)
                left = mid + 1;
            else
                right = mid - 1;
        }

        if(arr[left] == num)
            return left;

        //Element not found
        return -1;
    }

}