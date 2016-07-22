// https://www.interviewbit.com/problems/redundant-braces/

int Solution::braces(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<char> st;
    
    for(int i = 0; i < A.size(); i++){
        if((A[i] == '{') || (A[i] == '[') || (A[i] == '(')){
            st.push(A[i]);
        }
        else if((A[i] == '}') || (A[i] == ']') || (A[i] == ')')){
            int topEl = st.top();
            st.pop();
            char sign = st.top();
            st.pop();
            if(sign == '+'){
                int botEl = st.top();
                st.pop();
                st.pop();
                st.push(botEl + topEl);
            }
            else if(sign == '-'){
                int botEl = st.top();
                st.pop();
                st.pop();
                st.push(botEl - topEl);
                
            }
            else if(sign == '*'){
                int botEl = st.top();
                st.pop();
                st.pop();
                st.push(botEl * topEl);
            }
            else if(sign == '/'){
                int botEl = st.top();
                st.pop();
                st.pop();
                st.push(botEl / topEl);
            }
            else{
                return 1;
            }
            
        }
        else{
            st.push(A[i]);
        }
    }
    
    return 0;
}
