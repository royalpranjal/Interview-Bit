//  https://www.interviewbit.com/problems/largest-permutation/


vector<int> Solution::solve(vector<int> &a, int b) {
    
     int n=a.size();
    
    vector<int> b1(n+1);
    b1[0]=0;
    
    for(int i=0;i<n;i++){
        b1[a[i]]=i;
    }
    
    int c=0;
    for(int i=0;i<n;i++){
         if(c>=b)
         break;
        if(a[i]!=n-i){
            int x=a[b1[n-i]],y=a[i];
          swap(a[i],a[b1[n-i]]);
          int k1=b1[x];
          b1[x]=i;
          b1[y]=k1;
            c++;
        }
        
    }
    return a;
     
}