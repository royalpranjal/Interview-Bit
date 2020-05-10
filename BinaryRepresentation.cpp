#include<bits/stdc++.h>

string Solution::findDigitsInBinary(int num){

    string ans = "";
    if(num == 0)
        return "0";
    while(num != 1){
        if(num%2 == 0)
            ans += "0";
        else 
            ans += "1";
        num /= 2;
    }
    ans += "1";
    reverse(ans.begin(), ans.end());
    return ans;

}
