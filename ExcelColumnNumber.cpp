#include<bits/stdc++.h>

int Solution::titleToNumber(string s){

    int n = s.size();
    int ans = 0;
    int cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        ans += (pow(26, cnt) * (s[i] - 'A' + 1));
        cnt++;
    }
    return ans;

}
