//  https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/

int Solution::maxProfit(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> temp(A.size(), 0);
    
    int buy = A[0], flag = 0, i = 1, max_sell = INT_MIN;
    int sol = 0;
    while(i < A.size()){
        int diff = A[i] - A[i-1];
        if(diff > 0){
            sol = sol + diff;
        }
        i++;
    }
    
    return sol;
}
