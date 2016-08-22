// https://www.interviewbit.com/problems/all-factors/

vector<int> Solution::allFactors(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> sol;
    int count_st = 0;
    int count_end = 0;
    
    for(int i = 1; i <= sqrt(A); i++){
        if(A%i == 0){
            sol.insert(sol.begin()+count_st, i);
            count_st++;
            if(i != sqrt(A)){
                sol.insert(sol.end()-count_end, A/i);
                count_end++;
            }
        }
    }
    
    return sol;
}
