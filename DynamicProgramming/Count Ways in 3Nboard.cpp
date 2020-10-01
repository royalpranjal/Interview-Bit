#include<bits/stdc++.h>
#define ll int64_t
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define fastio cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

using namespace std;
const ll mod =1e9+7;
const int N =2e5+1;


// for counting->
int main() {
    int d[3]={1,2,3};
    int s[3]={1,2,1};
    
    cout<<"For diff->";
    int same=0,diff=0;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            for(int k=1;k<=4;k++){
                if(d[0]==i|| d[1]==j || d[2]==k) continue;
                if(i==j || j==k) continue;
                if(i==k) same++;
                else diff++;
            }
    cout<<same<<" "<<diff;

    cout<<"For Same->";
    same=0,diff=0;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            for(int k=1;k<=4;k++){
                if(s[0]==i || s[1]==j|| s[2]==k) continue;
                if(i==j || j==k) continue;
                if(i==k) same++;
                else diff++;
            }

    cout<<same<<" "<<diff;
    return 0;
}
