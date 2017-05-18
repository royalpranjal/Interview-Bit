vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> sol;
    
    deque<int> q;
    
    int i = 0;
    
    while(i < B){
        while(!q.empty() && A[i] >= A[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        i++;
    }
    
    sol.push_back(A[q.front()]);
    
    while(i < A.size()){
        if(i - q.front() >= B){
            q.pop_front();
        }
        while(!q.empty() && A[i] >= A[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        sol.push_back(A[q.front()]);
        i++;
    }
    
    return sol;
}
