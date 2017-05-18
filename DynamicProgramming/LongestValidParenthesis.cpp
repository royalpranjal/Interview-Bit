int Solution::longestValidParentheses(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int sol = 0, curr = 0, start = -1;
    int i = 0;
    
    stack<int> st;
    st.push(-1);
    
    while(i < A.size()){
        if(A[i] == '('){
            st.push(i);
        }
        else{
            st.pop();
            if(!st.empty()){
                sol = max(i-st.top(), sol);    
            }
            else{
                st.push(i);
            }
        }
        i++;
    }    
    
    
    return sol;
}
