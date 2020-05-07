int Solution::solve(vector<vector<int> > &A) {

    int hist[A.size()+1][A[0].size()+1];

    for (int i=0; i<A[0].size(); i++)
    {
        hist[0][i] = A[0][i];

        for (int j=1; j<A.size(); j++)
            hist[j][i] = (A[j][i]==0)? 0: hist[j-1][i]+1;
    }


    for (int i=0; i<A.size(); i++)
    {
        int count[A.size()+1];
        memset( count, 0, (A.size()+1)*sizeof(int) );

        for (int j=0; j<A[0].size(); j++)
            count[hist[i][j]]++;

        int col_no = 0;
        for (int j=A.size(); j>=0; j--)
        {
            if (count[j] > 0)
            {
                for (int k=0; k<count[j]; k++)
                {
                    hist[i][col_no] = j;
                    col_no++;
                }
            }
        }
    }

    int curr_area, max_area = 0;
    for (int i=0; i<A.size(); i++)
    {
        for (int j=0; j<A[0].size(); j++)
        {
            curr_area = (j+1)*hist[i][j];
            if (curr_area > max_area)
                max_area = curr_area;
        }
    }
    return max_area;
}
