void aux(int i, int sum, int k, vector<int> &A, vector<int> &temp, set<vector<int>> &ans) {
    if(i == A.size() || sum >= k){
        if(sum == k){
            ans.insert(temp);
        }
        return;
    }

    temp.push_back(A[i]);
    aux(i, sum+A[i], k, A, temp, ans);
    aux(i+1, sum+A[i], k, A, temp, ans);
    temp.pop_back();
    aux(i+1, sum, k, A, temp, ans);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    set<vector<int>> ans;
    sort(A.begin(), A.end());
    vector<int> temp;
    aux(0, 0, B, A, temp, ans);
    vector<vector<int>> res;
    
    for(auto i = ans.begin(); i != ans.end(); i++){
        res.push_back(*i);
    }
    return res;
}
