vector<int> Solution::solve(int A, vector<int> &B) 
{
    int mn = INT_MAX;
    int n = B.size(),i,j,pos;
    for(i=0;i<n;i++)
    {
        if(B[i]<mn)
        {
            mn = B[i];
            pos = i;
        }
    }
        //mn = min(B[i],mn);
    int maxkick = A/mn;
    
    vector<int> order;
    for(i=0;i<maxkick;i++)
        order.push_back(pos);
        
    int rem = maxkick*mn;
    rem = A-rem;
    i = 0;
    while(i<maxkick)
    {
        pos = order[i];
        int ind = -1;
        for(j=0;j<n;j++)
        {
            if(rem-B[j]+B[pos] >= 0) 
            {
                ind = j;
                rem = rem-B[j]+B[pos];
                break;
            }
        }
        if(j == n)
            break;
        order[i] = j;
        i++;
       // pos = order.size();
    }
    return order;
}
