//reference: https://www.geeksforgeeks.org/largest-number-divides-x-co-prime-y/
//Note: you can write the function for gcd [i'm using inbuilt gcd function in c++]

int Solution::cpFact(int x, int y) {

    while (__gcd(x, y) != 1) {
        x = x / __gcd(x, y);
    }
    return x;
}
