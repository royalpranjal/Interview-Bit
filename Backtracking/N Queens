vector<vector<string> >ans;
int n;

void recur(int ind, vector<int> pos)
{
    int i,j;
    if(ind == n)
    {
       vector<string> valid;
        for(i=0;i<n;i++)
        {
            string row = "";
            for(j=0;j<n;j++)
            {
                if(j == pos[i])
                    row += 'Q';
                else
                    row += '.';
            }
            valid.push_back(row);
        }
        ans.push_back(valid);
    
        return;
    }
    for(i = 0;i<n;i++)
    {
        bool flag = true;
        for(j=0;j<pos.size();j++)
        {
            if(abs(ind-j) == abs(pos[j]-i) || i == pos[j])
                flag = false;
        }
        if(!flag)
            continue;
        pos.push_back(i);
        recur(ind+1,pos);
        pos.pop_back();
        //pos[ind] = -1;
    }
}
vector<vector<string> > Solution::solveNQueens(int A) 
{
    ans.clear();
    vector<int> pos;
    int i;
    n = A;
    recur(0,pos);
    return ans;
}
