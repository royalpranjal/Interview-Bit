// https://www.interviewbit.com/problems/min-sum-path-in-triangle/

int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() == 0){
        return 0;
    }
    
    int total[A.size()];
 
    int l = A.size() - 1;
  
    for (int i = 0; i < A[l].size(); i++) 
    {
        total[i] = A[l][i];
    }
  
    for (int i = A.size() - 2; i >= 0; i--) 
    {
        for (int j = 0; j < A[i + 1].size() - 1; j++) 
        {
            total[j] = A[i][j] + min(total[j], total[j + 1]);
        }
    }
  
    return total[0];
}
