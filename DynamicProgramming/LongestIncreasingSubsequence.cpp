// https://www.interviewbit.com/problems/longest-increasing-subsequence/

int Solution::lis(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() == 0){
        return 0;
    }
    
    vector<int> val(A.size(), 1);
    
    int sol = 1;
    
    for(int i = 1; i < A.size(); i++){
        for(int j = 0; j < i; j++){
            if(A[i] > A[j]){
                val[i] = max(val[j]+1, val[i]);
                if(val[i] > sol){
                    sol = val[i];
                }
            }
        }
    }
    
    return sol;
}
