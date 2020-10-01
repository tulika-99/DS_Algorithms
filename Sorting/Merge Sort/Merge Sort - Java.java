import java.util.Arrays;

class MergeSortAlgo {

    public static void main(String args[]) throws Exception {

        int[] a = new int[10];
        for (int i = 10, j = 0; i > 0 && j < 10; i--, j++)
            a[j] = i;

        a = MergeSort(a);

        for (int i = 0; i < 10; i++)
            System.out.print(a[i] + " ");
        System.out.println();

    }

    public static int[] MergeSort(int a[]) {

        if (a.length <= 1)
            return a;

        return merge(MergeSort(Arrays.copyOfRange(a, 0, a.length / 2)),
                MergeSort(Arrays.copyOfRange(a, a.length / 2, a.length)));

    }

    public static int[] merge(int[] left, int[] right) {
        int[] a = new int[left.length + right.length];
        int i = 0, j = 0, z = 0;
        while ((i < left.length) && (j < right.length)) {
            if (left[i] < right[j]) {
                a[z] = left[i];
                i++;
                z++;
            } else if (left[i] > right[j]) {
                a[z] = right[j];
                j++;
                z++;
            }
        }

        if (i != left.length) {
            while (i != left.length) {
                a[z] = left[i];
                i++;
                z++;
            }
        } else if (j != right.length) {
            while (j != right.length) {
                a[z] = right[j];
                j++;
                z++;
            }

        }

        return a;
    }
}