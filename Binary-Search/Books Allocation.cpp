#define ll long long
#include<bits/stdc++.h>
using namespace std;

// Book allocation problems
// Why binary search? Dont just use it !
// Brute force solution will be to check for each book
// note that books are to be allocated in continuous form else it would have been an n subset problem with minimum sum any approaches?
// Interviewer might can gove you a different problem which seems to be solved this way but actually could have been different
// STRATEGY->
// Naive solution
// Notice the function graph
// boom! binary search cna be a solution

bool is(ll x, vector<int> & book,int m){
    ll cnt=1,curr=0;
    for(int i=0;i<book.size();i++) 
        if(curr+book[i]<=x) curr+=book[i];  // note curr does not counts the number of books in a set!!
        else cnt++,curr=book[i];
    if(cnt<=m) return 1;
    return 0;
}

int books(vector<int> &book, int m) {
    int n=book.size();
    if((m==0&&n!=0) || m>n) return -1;
    
    ll lo=0,hi=0,res=0;
    for(int i=0;i<n;i++){
        lo=max(lo,1LL*book[i]);
        hi+=book[i];
    }
    
    // using binary search
    while(lo<=hi){
        ll mid = (hi+lo)>>1;
        if(is(mid,book,m)) res=mid,hi=mid-1;
        else lo=mid+1;
    }
    
    return res;
}
