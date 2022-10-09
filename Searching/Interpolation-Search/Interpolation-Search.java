public class Interpolation {

    public static void main(String[] args){
        int nums[] = {23,56,212,657,754,987,1112,1535,2513};
        int find = 1535;
        int index_result = InterpolationSearch(nums, find);
        System.out.println(find + " is found at index " + index_result);
    }

    public static int InterpolationSearch(int[] nums, int searched_num) {
        int low_num = 0;
        int high_num = nums.length - 1;
        int mid_num;
        while (nums[high_num] != nums[low_num] && nums[low_num] < searched_num && nums[high_num] >= searched_num) {
            mid_num = low_num + ((searched_num - nums[low_num]) * (high_num - low_num) / (nums[high_num] - nums[low_num]));
            if (searched_num > nums[mid_num])
                low_num = mid_num + 1;
            else if (searched_num < nums[mid_num])
                high_num = mid_num - 1;
            else
                return mid_num;
        }
        if (nums[low_num] == searched_num) {
            return low_num;
        } else {
            return -1;
        }
    }
}
