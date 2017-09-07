void make(vector<int> temp, int curr, int n, int k, vector<vector<int> >& ans){
    if(temp.size() == k){
        ans.push_back(temp);
        return;
    }
    else if(curr > n){
        return;
    }
    
    for(int i = curr; i <= n; i++){
        vector<int> t(temp);
        t.push_back(i);
        make(t, i+1, n, k, ans);
    }
}

vector<vector<int> > Solution::combine(int n, int k) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int> > ans;
    
    for(int i = 1; i <= n; i++){
        vector<int> temp(1, i);
        make(temp, i+1, n, k, ans);
    }
    
    return ans;
}
