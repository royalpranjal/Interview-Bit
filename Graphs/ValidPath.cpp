//https://www.interviewbit.com/problems/valid-path/

int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 1, 0, -1, 1, 0, -1};

bool issafe(int x1, int y1, int x2, int y2, int r)
{
    int d = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
    int r2 = r * r;
    return (d > r2);
}

bool isin(int x, int y, int r, int c)
{
    if((x < 0) || (y < 0) || (x > r) || (y > c))
        return false;
    return true;    
}

void dfs(int x, int y, int r, int c, vector<vector<bool> >&safe, vector<vector<bool> >&visited)
{
    if(!safe[x][y])
        return;
        
    visited[x][y] = true;   
    
    for(int i = 0; i < 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        
        if(isin(nx, ny, r, c) && (!visited[nx][ny]))
            dfs(nx, ny, r, c, safe, visited);
    }
}

string Solution::solve(int r, int c, int n, int R, vector<int> &X, vector<int> &Y) 
{
    vector<vector<bool> > safe(r + 1, vector <bool> (c + 1, true));
    vector<vector<bool> > visited(r + 1, vector <bool> (c + 1, false));
    
    for(int i = 0; i <= r; i++)
    {
        for(int j = 0; j <= c; j++)
        {
            for(int k = 0; k < n; k++)
            {
                safe[i][j] = issafe(i, j, X[k], Y[k], R);
                
                if(!safe[i][j])
                    break;
            }
        }
    }
    
    dfs(0, 0, r, c, safe, visited);
    
    if(visited[r][c])
        return string ("YES");
    return string ("NO");    
}
