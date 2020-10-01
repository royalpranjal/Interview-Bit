// Given a rowWise sorted array find matrix median of the array
// Naive -> (N*M) log(N*M)              Aux->space O(N*M)
// MEGRING SORTED ARRAYS-> (N*M) LOG(M) Aux->space O(N*M) 
// BSearch-> (32*N*LOG(M))              Aux->space O(32)/ Dont say O(32) say constant
// in bsearch logn steps are there but each step is having O(1) space so even after the search extra space will be used only once
// but in Merging Sorted arrays recursive func is there so at any time space might be o(1)*logM steps

#include<bits/stdc++.h>
using namespace std;

int cnt(int x, vector<vector<int>> &A){
    int cnt=0;
    for(auto v:A) cnt+=(lower_bound(v.begin(),v.end(),x)-v.begin());    
    return cnt;
}

int findMedian(vector<vector<int> > &A) {
    int hi=INT_MIN,lo=INT_MAX,res=INT_MIN,r=A.size(),c=A[0].size();
    
    for(auto v:A) for(auto x:v) hi=max(hi,x), lo=min(lo,x);
    while(lo<=hi){
        int mid= (lo+hi)>>1;
        if(cnt(mid,A)*2<r*c) res=mid,lo=mid+1;
        else hi=mid-1;
    }
    if(res==INT_MIN) return A[0][0];
    return res;
}
