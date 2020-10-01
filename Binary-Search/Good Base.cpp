#define ll long long
#include<bits/stdc++.h>
using namespace std;
// still we not know when to use binary search!
string solve(string A) {
    ll n = stoll(A);
    ll res=n-1,temp,mul;
    temp=(sqrt(4*n-3)-1)/2;

    if(n!=3 && temp*temp+temp+1==n) res=temp;
    temp=0;

    for(int i=3;i<64;i++){ // at most 1e6+1e4+1e2...
        ll j=1; temp=0;
        // we can use binary search for this !!!!
        while(temp<n){
            j++;
            temp=0; mul=1;
            for(int k=0;k<=i;k++) temp+=mul,mul*=j;
        }
        if(temp==n) res=j;
    }
    return to_string(res);
}

/*
string Solution::solve(string n) {
        long long num = stol(n);
        for (int i = log(num ) / log(2); i >= 2; --i) {
            long long left = 2, right = pow(num, 1.0 / (i-1)) + 1;
            while (left < right) {
                long long mid = left + (right - left) / 2, sum = 0;
                for (int j = 0; j < i; ++j) {
                    sum = sum * mid + 1;
                }
                if (sum == num) return to_string(mid);
                else if (sum < num) left = mid + 1;
                else right = mid;
            }
        }
        return to_string(num - 1);
}
*/