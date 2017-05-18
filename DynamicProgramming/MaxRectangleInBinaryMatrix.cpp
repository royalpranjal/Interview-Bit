int Solution::maximalRectangle(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() == 0){
        return 0;
    }
    
    vector<int> temp(A[0].size(), 0);
    
    int i = 0;
    
    int sol = 0;
    
    while(i < A.size()){
        
        for(int k = 0; k < A[i].size(); k++){
            if(A[i][k] == 0){
                temp[k] = 0;
            }
            else{
                temp[k] = temp[k] + A[i][k];
            }
        }
        
        stack<int> st;
        
        int j = 0;
        
        while(j < temp.size()){
            if(st.empty() || temp[st.top()] <= temp[j]){
                st.push(j);
                j++;
            }
            else{
                int top = st.top();
                st.pop();
                
                int area = 0;
                
                if(st.empty()){
                    area = temp[top] * j;
                }
                else{
                    area = temp[top] * (j - st.top() - 1);
                }
                
                sol = max(sol, area);
            }
        }
        
        while(!st.empty()){
            int top = st.top();
            st.pop();
            
            int area = 0;
            
            if(st.empty()){
                area = temp[top] * j;
            }
            else{
                area = temp[top] * (j - st.top() - 1);
            }
            
            sol = max(sol, area);
        }
    
        i++;    
    }
    
    return sol;
}
