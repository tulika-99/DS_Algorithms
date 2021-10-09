class Search
    {
        static void Main(String[] args)
        {
            int result;
            int[] arr = { 2, 8, 16, 59, 13 };

            result = binarySearch(arr, 13);

            Console.WriteLine(result);
            Console.ReadKey();
        }

        // Binary Search function returns location of number in array or -1 if not found
        private static int binarySearch(int[] arr, int num)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] == num)
                {
                    return i;
                }
            }

            //Element not found
            return -1;
        }
    }
