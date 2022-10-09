namespace Kadanes
{
    internal class Program
    {
        internal static int MaxSubArraySum(int[] collection)
        {
            var maxSum = 0;
            var currentSum = 0;

            for (int i = 0; i < collection.Length; i++)
            {
                currentSum = currentSum + collection.ElementAt(i);
                if (maxSum < currentSum)
                    maxSum = currentSum;

                if (currentSum < 0)
                    currentSum = 0;
            }
            return maxSum;
        }

        static void Main()
        {
            Console.WriteLine("Write an array using ',' as a delimiter. For example - 1, 2, 3");
            var userInput = Console.ReadLine();
            var collection = userInput.Split(',').Select(x => int.Parse(x)).ToArray();
            var maxSubArraySum = MaxSubArraySum(collection);
            Console.WriteLine($"Maximum subarray sum: {maxSubArraySum}");
        }
    }
}
