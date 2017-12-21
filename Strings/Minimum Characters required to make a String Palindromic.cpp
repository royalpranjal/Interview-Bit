int Solution::solve(string A) {
    int n = A.size(), match = 1;
    
    if(n == 0){
        return 0;
    }
    
    for(int i = 1; i < n; i++){
        int start = 0, end = i, pal = 1;
        while(start < end){
            if(A[start] != A[end]){
                pal = 0;
                break;
            }
            start++;
            end--;
        }
        
        if(pal){
            match = i + 1;
        }
    }
    
    return n - match; 
}
