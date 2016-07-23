// https://www.interviewbit.com/problems/evaluate-expression/

int Solution::evalRPN(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<int> st;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/"){
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            if(A[i] == "+"){
                st.push(second+first);
            }
            else if(A[i] == "-"){
                st.push(second-first);
            }
            else if(A[i] == "*"){
                st.push(second*first);
            }
            else{
                st.push(second/first);
            }
        }
        else{
            st.push(atoi(A[i].c_str()));
        }
    }
    
    return st.top();
       
}
