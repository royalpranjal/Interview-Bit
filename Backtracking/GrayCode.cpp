void grayCodeUtil(vector<int>& res, int A, int& num){
    if (A == 0) { 
        res.push_back(num); 
        return; 
    } 
    // ignore the bit. 
    grayCodeUtil(res, A - 1, num); 
  
    // invert the bit. 
    num = num ^ (1 << (A - 1)); 
    grayCodeUtil(res, A - 1, num); 
}

vector<int> Solution::grayCode(int A){
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> sol;
    int k =0;
    grayCodeUtil(sol, A, k);
    return sol;
}
