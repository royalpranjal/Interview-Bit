// https://www.interviewbit.com/problems/assign-mice-to-holes/

int Solution::mice(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() == 0){
        return 0;
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int i = 0, j = 0;
    int sol = INT_MIN;
    
    while(i != A.size()){
        sol = max(abs(A[i]-B[j]), sol);
        i++;
        j++;
        if(j == B.size()){
            j--;
        }
    }
    
    return sol;
}
