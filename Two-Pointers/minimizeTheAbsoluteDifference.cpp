int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i,n1,n2,n3,j,k,x,mx,mn,t,a,b,c;
        int ans,diff=INT_MAX,curr;
        i=0;
        j=0;
        k=0;
        n1=A.size();
        n2=B.size();
        n3=C.size();
        int cnt1,cnt2,cnt3;
        while(i<n1&&j<n2&&k<n3){
            cnt1=0;
            cnt2=0;
            cnt3=0;
            mx=max(max(A[i],B[j]),C[k]);
            mn=min(min(A[i],B[j]),C[k]);
            curr=mx-mn;
            a=A[i];
            b=B[j];
            c=C[k];
            if(diff>curr){
                diff=curr;
            }
            if(mn==a){
                i++;
            }
            else if(mn==b){
                j++;
            }
            else{
                k++;
            }
        }
 
    return diff;
}
