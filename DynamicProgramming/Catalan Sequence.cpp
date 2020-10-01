const int mod =1e9+7;
void EE(int aa, int bb, int& xx, int& yy){if(aa%bb == 0){xx=0,yy=1;return;}
EE(bb,aa%bb,xx,yy);int t = xx;xx = yy;yy = t - yy*(aa/bb);}
int mmi(int aa){int xx,yy;EE(aa,mod,xx,yy);xx = (xx+mod)%mod;return xx;}

int getCatalan(int A){
    int res=1;
    for(int i=2;i<=A;i++) res= (1LL*res*(A+i))%mod;
    for(int i=2;i<=A;i++) res= (1LL*res*mmi(i))%mod;
    return res;
}

int dpSol(int A){
    vector<int>dp(A+1,0);
    dp[1]=dp[0]=1;
    for(int i=2;i<=A;i++) for(int j=0;j<i;j++) dp[i]=(dp[i]+1LL*dp[j]*dp[i-1-j])%mod;
    return dp[A];
}
int chordCnt(int A) {
    if(A==0) return 0;
    return dpSol(A);
    return getCatalan(A);
}
