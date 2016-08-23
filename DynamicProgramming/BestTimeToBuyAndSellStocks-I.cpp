// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/

int Solution::maxProfit(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A.size() == 0){
        return 0;
    }
    
    int sol = 0, min_p = A[0];
    
    for(int i = 1; i < A.size(); i++){
        if(A[i] < min_p){
            min_p = A[i];
        }
        sol = max(sol, A[i] - min_p);
    }
    
    return sol;
}
