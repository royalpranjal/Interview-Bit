void getAns(vector<int> &A, int start, vector<vector<int> > &sol, int size){
    for(int i=start;i<A.size();++i){
        swap(A[start], A[i]);
        if(size== A.size()-1) sol.push_back(A);
        getAns(A, start+1, sol, size+1);
        swap(A[start], A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A){
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A.size() == 1){
        vector<vector<int>> sol;
        sol.push_back(A);
        return sol;
    }
    vector<vector<int>> sol;
    getAns(A, 0, sol, 1);
    return sol;
}