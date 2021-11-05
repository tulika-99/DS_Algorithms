//
// Created by Vinicius Araújo on 11/5/21.
//


/*
 *
 * this tests uses the fact that a^(p-1) % p == 1 if p and a are co-primes. test can
 * be true for a non-prime number so the test uses random and multiple a's
 *
 */

#include <iostream>

long long binaryPower(long long a, long long b, long long p){
    a %= p;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

bool fermatPrimalityTest(long long n){
    unsigned char it = 15;
    if(n < 4){
        return n==3 || n==2;
    }
    for(int i = 0; i < it; i++){
        long long a = 2 + rand() % (n-3);
        if(binaryPower(a,n-1,n) != 1){
            return false;
        }
    }
    return true;
}

int main(){
    long long n;
    std::cin >> n;
    if(fermatPrimalityTest(n)){
        std::cout << n << " is Prime" << std::endl;
    }
    else{
        std::cout << n << " is not Prime" << std::endl;
    }
    return 0;
}