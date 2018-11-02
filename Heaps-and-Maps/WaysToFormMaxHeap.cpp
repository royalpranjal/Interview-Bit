long long dp[105];
long long comb[105][105];
#define MOD 1000000007
int rec(int n)
{
    if(n<=1)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    int i;
    int fill = 0;
    int pw = 2;
    int left,right;
    left = right = 0;
    
    while(fill+pw < n-1)
    {
        fill += pw;
        left += pw/2;
        right += pw/2;
        pw *= 2;
    }
    int rem = n-1-fill;
    if(rem > pw/2)
    {
        left += pw/2;
        right += (rem-pw/2);
    }
    else
        left += rem;

    return dp[n] = (((rec(left)*1LL*rec(right))%MOD)*1LL*comb[n-1][left])%MOD;
}
int Solution::solve(int A)
{
    int i,j;
    for(i=0;i<=100;i++)
        dp[i] = -1;
    comb[0][0] = 1;
    for(i=1;i<=100;i++)
    {
        comb[i][0] = comb[i][i] = 1;
        for(j=1;j<i;j++)
            comb[i][j] = (comb[i-1][j-1]+comb[i-1][j])%MOD;
    }
    return rec(A);
}
