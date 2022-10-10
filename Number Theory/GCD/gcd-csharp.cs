namespace Gcd
{
    internal class Program
    {
        static int Gcd(int first, int second)
        {
            while (first != second)
            {
                if (first > second)
                {
                    first = first - second;
                }
                else
                {
                    second = second - first;
                }
            }

            return second;
        }

        static void Main()
        {
            Console.WriteLine("Enter first integer number:");
            var first = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter second integer number:");
            var second = Convert.ToInt32(Console.ReadLine());

            var gcd = Gcd(first, second);
            Console.WriteLine($"GCD: {gcd}");
        }
    }
}
