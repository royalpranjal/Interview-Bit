int check(priority_queue<int>& q, int& A){
    int ans = 0, divi = pow(10, 9) + 7;
    
    while(A){
        int top = q.top();
        
        ans = (ans + (top%divi))%divi;
        
        q.pop();
        q.push(top/2);
        
        A--;
    }
    
    return ans;
}

int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> q;
    
    if(B.size() == 0){
        return 0;
    }
    
    for(int i = 0; i < B.size(); i++){
        q.push(B[i]);
    }

    return check(q, A);
}
