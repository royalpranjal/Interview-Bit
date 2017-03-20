int Solution::largestRectangleArea(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    stack<int> st;
    
    int sol = 0;
    
    int i = 0, n = A.size();
    
    while(i < n){
        if(st.empty() || A[st.top()] <= A[i]){
            st.push(i);
            i++;
        }
        else{
            int top = st.top();
            st.pop();
            
            int area = 0;
            
            if(st.empty()){
                area = A[top] * i;
            }
            else{
                area = A[top] * (i - st.top() - 1);
            }
            
            sol = max(sol, area);
        }
    }
    
    while(!st.empty()){
        int top = st.top();
        st.pop();
        
        int area = 0;
        
        if(st.empty()){
            area = A[top] * i;
        }
        else{
            area = A[top] * (i - st.top() - 1);
        }
        
        sol = max(sol, area);
    }
    
    return sol;
    
}
