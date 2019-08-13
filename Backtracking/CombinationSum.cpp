void getAns(vector<int> &A, int B, vector<vector<int>> &sol, vector<int> &cur, int start, int curSum){
    if(curSum>B) return;
    if(B == curSum){
        sol.push_back(cur);
    }
    
    for(int i=start;i<A.size();++i){
        cur.push_back(A[i]);
        curSum += A[i];
        getAns(A, B, sol, cur, i, curSum);
        cur.pop_back();
        curSum -= A[i];
    }
}

vector<vector<int>> Solution::combinationSum(vector<int> &A, int B){
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(), A.end());
    vector<int>::iterator ip;
    ip = std::unique(A.begin(), A.end());
    A.resize(std::distance(A.begin(), ip));
    
    vector<vector<int>>sol;
    vector<int> cur;
    getAns(A, B, sol, cur, 0, 0);
    return sol;
}