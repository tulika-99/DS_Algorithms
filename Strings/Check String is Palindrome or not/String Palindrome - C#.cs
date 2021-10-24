using System;

namespace Palindrome
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine("Enter a word :");
            string s = Console.ReadLine();

            if (IsPalindrome(s))
                Console.WriteLine(s + " is palindrome");
            else
                Console.WriteLine(s + " is not palindrome");
            
            Console.ReadKey();
        }

        private static bool IsPalindrome(String s)
        {
            int i = 0;
            int j = s.Length - 1;
            while (i <= j)
            {
                if (s[i] != s[j])
                    return false;
                i++;
                j--;
            }
            return true;
        }
    }
}
