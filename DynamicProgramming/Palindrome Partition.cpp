vector<vector<bool>> isPad;
vector<int> dp;

void cr(string &A){
    isPad=vector<vector<bool>>(A.size()+1,vector<bool>(A.size()+1));
    dp=vector<int>(A.size()+1,-1);
}

void generatePads(string &A){
    int n=A.size();
    for(int i=0;i<n;i++) isPad[i][i]=1;
    for(int i=0;i<n-1;i++) isPad[i][i+1]=A[i]==A[i+1];
    for(int l=3;l<=n;l++) for(int i=0,j=l-1;j<n;i++,j++)
        isPad[i][j]=(A[i]==A[j] && isPad[i+1][j-1]);
}

int solve(int i, string &s){
    if(i==s.size()) return dp[i]=0;
    if(dp[i]!=-1)   return dp[i];
    dp[i]=1e6;
    for(int k=i;k<s.size();k++) 
    if(isPad[i][k]) dp[i]=min(dp[i],solve(k+1,s)+1);
    return dp[i];
}

int Solution::minCut(string A) {
    if(A.size()==0) return 0;
    cr(A);
    generatePads(A);
    return solve(0,A)-1;
}
