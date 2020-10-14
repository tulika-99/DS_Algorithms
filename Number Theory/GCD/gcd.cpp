/*
  GCD
  Calculate and return GCD of two given numbers x and y. Numbers are within range of Integer.
*/

int gcd(int a,int b)
{
    if (b == 0) {
            return a;
        }

        return gcd(b, a % b);
}

// Driver code

int main(){
    int a, b;
    cin>>a>>b;
    cout<<gcd(a,b);
}
