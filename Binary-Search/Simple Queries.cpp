#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define re cin>>
#define pr cout<<
#define all(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)


const int N=2e6+5;
const int mod=1e9+7;

#define ll unsigned long long
const int  mod = 1e9+7;

ll count(int x){
    ll res=1;
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            res=(res*(i))%mod;
            if(x==i*i) continue;
            res=(res*(x/i))%mod;
        }
    }
    return res%mod;
}

vector<int> solve(vector<int> &A, vector<int> &B) {
    int n=A.size();
    vector<ll> times(n+1),order(n);
    stack<int> st;
    for(int i=0;i<A.size();i++){
        while(!st.empty() && A[st.top()]<A[i]){
            int p=st.top(); st.pop();
            int l=st.size()?st.top()+1:0;
            int r=i-1;
            times[p]=(p-l+1LL)*(r-p+1);
        }
        st.push(i);
    }
    while(!st.empty()){
        int p=st.top(); st.pop();
        int l=st.size()?st.top()+1:0;
        times[p]=(p-l+1LL)*(n-1-p+1);
    }
    
    vector<pair<int,int>> pp;
    for(int i=0;i<n;i++) pp.push_back(make_pair(count(A[i]),times[i]));
    sort(pp.begin(),pp.end(),greater<pair<int,int>>());
    
    ll sum=0;
    for(int i=0;i<n;i++) order[i]=(sum+=pp[i].second);
    for(int i=0;i<B.size();i++)
        B[i] =pp[lower_bound(order.begin(),order.end(),B[i])-order.begin()].first;
    return B;
}

int main(){
      
      cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
      
      
      return 0;
}

