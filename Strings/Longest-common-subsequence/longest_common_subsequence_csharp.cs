namespace LcsLength
{
    internal class Program
    {
        static int LcsLength(string first, string second)
        {
            int m = first.Length;
            int n = second.Length;
            int[,] C = new int[m + 1, n + 1];
            for (int i = 0; i <= m; i++)
                C[i, 0] = 0;
            for (int j = 0; j <= n; j++)
                C[0, j] = 0;
            for (int i = 1; i <= m; i++)
                for (int j = 1; j <= n; j++)
                {
                    if (first[i - 1] == second[j - 1])
                        C[i, j] = C[i - 1, j - 1] + 1;
                    else
                        C[i, j] = Math.Max(C[i, j - 1], C[i - 1, j]);
                }
            return C[m, n];
        }

        static void Main()
        {
            Console.WriteLine("Write first string:");
            var first = Console.ReadLine();

            Console.WriteLine("Write second string:");
            var second = Console.ReadLine();

            var lcsLength = LcsLength(first, second);
            Console.WriteLine($"Length LCS: {lcsLength}");
        }
    }
}
