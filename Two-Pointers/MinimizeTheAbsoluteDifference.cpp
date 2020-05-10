int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i = A.size()-1,j=B.size()-1,k=C.size()-1;
    int minn =INT_MAX;
    while(i!=-1 && j!=-1 && k!=-1){
        int cur = max(A[i],max(B[j],C[k]))-min(A[i],min(B[j],C[k]));
        if(cur < minn){
            minn=cur;
        }
        int maxx = max(A[i],max(B[j],C[k]));
        if(maxx == A[i]){
            i-=1;
        }else if(maxx == B[j]){
            j-=1;
        }else{
            k-=1;
        }
    }
    return minn;
}