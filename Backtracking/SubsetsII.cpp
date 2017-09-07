void make(vector<int>& A, int curr, int n, vector<int> temp, vector<vector<int> >& ans, map<vector<int>, bool>& m){
    if(m.find(temp) != m.end()){
        return;
    }
    ans.push_back(temp);
    m[temp] = true;
    if(curr == n){
        return;
    }
    
    for(int i = curr; i < n; i++){
        vector<int> t(temp);
        t.push_back(A[i]);
        make(A, i+1, n, t, ans, m);
    }
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int> > ans;
    vector<int> temp;
    ans.push_back(temp);
    
    int n = A.size();
    
    if(n == 0){
        return ans;
    }
    
    sort(A.begin(), A.end());
    
    map<vector<int>, bool> m;
    
    for(int i = 0; i < n; i++){
        vector<int> temp;
        temp.push_back(A[i]);
        make(A, i+1, n, temp, ans, m);
    }
    
    return ans;
}
