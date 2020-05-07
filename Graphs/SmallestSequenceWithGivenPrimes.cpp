vector<int> Solution::solve(int A, int B, int C, int D)
{
    set<int> s;
    swap(A,D);
    int ctr = 0;
    vector<int> ans;
    s.insert(B);
    s.insert(C);
    s.insert(D);
    while(ctr<A)
    {
        auto i = s.begin();
        ans.push_back(*i);
    
        s.insert((*i)*B);
        s.insert((*i)*C);
        s.insert((*i)*D);
        s.erase(i);
        ctr++;
    }
    return ans;
}
