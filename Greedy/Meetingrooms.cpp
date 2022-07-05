// https://www.interviewbit.com/problems/meeting-rooms/

int Solution::solve(vector<vector<int> > &A) {
    int n=A.size();
    assert(n>=1 && n<=100000);
    for(auto b:A)
        for(int a:b)
        assert(a>=0 && a<=2000000000);
    int start[n];
    int end[n];
    for(int i=0;i<n;i++)
    {
        start[i]=A[i][0];
        end[i]=A[i][1];
    }
    sort(start,start+n);
    sort(end,end+n);
    int maxe=1;
    int i=1;
    int j=0;
    int room=1;
    while(i<n && j<n)
    {
        if(start[i]<end[j])
        {
            room++;
            i++;
        }
        else
        {
            room--;
            j++;
        }
        maxe=max(maxe,room);
    }
    return maxe;
}
