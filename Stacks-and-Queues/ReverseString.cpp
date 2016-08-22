// https://www.interviewbit.com/problems/reverse-string/

string Solution::reverseString(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    stack<char> rev;
    
    for(int i = 0; i < A.size(); i++){
        rev.push(A[i]);
    }
    
    string ans = "";
    
    int height = rev.size();
    
    
    for(int i = height-1; i >= 0; i--){
        ans = ans + rev.top();
        rev.pop();
    }
    
    return ans;
}
