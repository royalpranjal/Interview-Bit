vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int i,n=A.size(),j,x;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    vector<int>ans;
    priority_queue<pair<int,pair<int,int>>>q;
    set<pair<int,int>>s;
    q.push(make_pair(A[n-1]+B[n-1],make_pair(n-1,n-1)));
    s.insert(make_pair(n-1,n-1));
    int cnt=0;
    while(!q.empty()){
        if(cnt==n){
            break;
        }
        pair<int,pair<int,int>>p=q.top();
        ans.push_back(p.first);
        i=p.second.first;
        j=p.second.second;
        if(s.find(make_pair(i-1,j))==s.end()){
            q.push(make_pair(A[i-1]+B[j],make_pair(i-1,j)));
            s.insert(make_pair(i-1,j));
        }
        if(s.find(make_pair(i,j-1))==s.end()){
            q.push(make_pair(A[i]+B[j-1],make_pair(i,j-1)));
            s.insert(make_pair(i,j-1));
        }
        q.pop();
        cnt++;
    }
    return ans;
}
