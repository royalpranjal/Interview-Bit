vector<string> Solution::prettyJSON(string A) 
{
    int n = A.size(),i,j;
    vector< string >ans;
    int tbctr = 0;
    i = 0;
    bool flag = false;
    while(i<n)
    {
        string row = "";
        for(j=0;j<tbctr;j++)
            row += '\t';
            flag = false;
        for(j=i;j<n;j++)
        {
            if(A[j] == '[' || A[j] == '{')
            {
                if(flag)
                    ans.push_back(row);
                row = "";
                for(int k=0;k<tbctr;k++)
                    row += '\t';
                row += A[j];
                ans.push_back(row);
                i = j+1;
                tbctr++;
                
                break;
            }
            if(A[j] == ']' || A[j] == '}')
            {
                tbctr--;
                if(flag)
                    ans.push_back(row);
                row = "";
                for(int k=0;k<tbctr;k++)
                    row += '\t';
                row += A[j];
                if(j + 1 < n && A[j+1] == ',')
                    row += A[j++];
                ans.push_back(row);
                i = j+1;
                break;
            }
            row += A[j];
            flag = true;
            i = j+1;
            if(A[j] == ',')
            {
                if(flag)
                    ans.push_back(row);
                i = j+1;
                break;
            }
        }
      //  i = j+1;
    //    i++;
    }
    return ans;
}
