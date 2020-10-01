import java.util.*;
class LinearSearch
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();// Enter the size of an array
        int a[]=new int[n];
        for(int i=0;i<n;i++)
        {
            a[i]=sc.nextInt();
        }
        int x=sc.nextInt(); //Enter the element that to be searched
        
        for(int i=0;i<n;i++)
        {
            if(a[i]==x)
            {
                System.out.println(i);// Print the index of an element if the element is found
               System.exit(0);
            }
        }
        System.out.println(-1);
        
    }
}