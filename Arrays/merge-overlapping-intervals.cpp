//https://www.geeksforgeeks.org/merging-intervals/

bool compareInterval(Interval i1, Interval i2) 
{ 
    return (i1.start < i2.start); 
} 

vector<Interval> Solution::merge(vector<Interval> &A) {

    vector<Interval> sol;

    int i=1;

    sort(A.begin(),A.end(),compareInterval);
    
    Interval top;
    
    top.start=A[0].start;
    
    top.end=A[0].end;
    
    for(int i=1;i<A.size();i++)
    {
        if(A[i].start>top.end)
        {
            sol.push_back(top);
            top.start=A[i].start;
            top.end=A[i].end;
        }
        else if(A[i].end>top.end)
        {
            s.end=A[i].end;
        }
        
    }
    
    sol.push_back(s);
    return sol;
}
