// https://www.interviewbit.com/problems/prime-numbers/

vector<int> Solution::sieve(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<bool> val;
    vector<int> ans;
    
    int i;
    
    for(i = 0; i <= A; i++){
        val.push_back(true);
    }
    
    val[0] = false;
    
    for(i = 2; i <= sqrt(A); i++){
        if(val[i] == true){
            for(int j = 2; i*j <= A; j++){
                val[i*j] = false;
            }
        }
    }
    
    for(i = 2; i < val.size(); i++){
        if(val[i] == true){
            ans.push_back(i);
        }
    }
    
    return ans;
    
}
