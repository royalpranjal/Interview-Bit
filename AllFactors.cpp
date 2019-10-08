#include<bits/stdc++.h>

vector<int> Solution::allFactors(int num){

    vector<int> ans;
    for(int i = 1; i <= (int)(sqrt(num)); i++){
         if(num%i == 0){
            if(num/i == i){
                ans.push_back(i);
            }
            else{
                ans.push_back(i);
                ans.push_back(num / i);
            }
        }    
    }
    sort(ans.begin(), ans.end());
    return ans;

}
