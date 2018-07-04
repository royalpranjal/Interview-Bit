int Solution::longestSubsequenceLength(const vector<int> &A) {
    if(A.size() == 0){
        return 0;
    }
    
    vector<int> B;
    vector<int> C;
    
    for(int i=0;i<A.size();i++)
    {
        B.push_back(1);
    }
    
    
    for(int i=0;i<A.size();i++)
    {
        C.push_back(1);
    }
    
    for(int i=1; i<A.size(); i++)
    {
        for(int j=0; j<i; j++)
        {
            if(A[i]>A[j] && B[i]< B[j]+1)
            {
                B[i] = B[j]+1;
            }
        }
    }
    
    for(int i=A.size()-2; i>=0; i--)
    {
        for(int j=A.size()-1; j>i; j--)
        {
            if(A[i]>A[j] && C[i]< C[j]+1)
            {
                C[i] = C[j]+1;
            }
        }
    }
    
    int max1 = B[0]+C[0]-1;
    
    for(int i=1;i<A.size();i++)
    {
        if(B[i]+C[i]-1 > max1)
        {
            max1 = B[i]+C[i]-1;
        }
    }

    return max1;
}
