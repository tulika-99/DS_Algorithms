import java.util.Random;
import java.util.stream.Stream;

/**
 * Like Binary Search, Jump Search is a searching algorithm for sorted arrays.
 * The basic idea is to check fewer elements (than linear search) by jumping ahead by
 * fixed steps or skipping some elements in place of searching all elements.
 * <p>
 * Time Complexity : O(√n)
 * Auxiliary Space : O(1)
 */
class JumpSearch {
    /**
     * Linear Search implementation
     *
     * @param array Integer List to be searched
     * @param value Key being searched for
     * @return Location of the value
     */
    static int find(Integer[] array, Integer value) {
        int length = array.length; /* length of array */
        int blockSize = (int) Math.sqrt(length); /* block size to be jumped */

        int limit = blockSize;
        while (value > 0 && limit < array.length - 1) {
            limit = Math.min(limit + blockSize, array.length - 1);
        }

        for (int i = limit - blockSize; i <= limit; i++) {
            if (array[i].equals(value)) { /* execute linear search */
                return i;
            }
        }
        return -1; /* not found */
    }

    public static void main(String[] args) {
        //generate data
        Random random = new Random();
        int size = 200;
        int maxElement = 100;
        var integers = Stream.generate(() -> random.nextInt(maxElement)).limit(size).toArray(Integer[]::new);

        //the element that should be found
        var searchValue = integers[random.nextInt(size - 1)];

        int atIndex = find(integers, searchValue);

        if (atIndex == -1) System.out.println("Element not found!");
        else System.out.println("Element found!");

        System.out.println(
                String.format(
                        "Value to search : %d \n" +
                                "Found at index  : %d \n" +
                                "An array length : %d",
                        searchValue,
                        atIndex,
                        size));
    }
}
