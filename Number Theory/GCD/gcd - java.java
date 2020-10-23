
// Question :- Given two integer number and we have to find the GCD of those number.

// Implementation

import java.util.Scanner;

public class GCD { 

    public int gcdFinder(int num1, int num2) {
        if (num2 == 0) {
            return num1;
        }
        return gcdFinder(num2, num1 % num2);
    }
    
    public static void main(String [] args) {
        GCD obj = new GCD();
        Scanner sc = new Scanner(System.in);
        int num1 = sc.nextInt();
        int num2 = sc.nextInt();
        System.out.println(obj.gcdFinder(num1, num2));
    }
}