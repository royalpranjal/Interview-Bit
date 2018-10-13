vector<int> x ({1, 2, 2, 1, -1, -2, -1, -2});
vector<int> y ({2, 1, -1, -2, 2, 1, -2, -1});

bool isSafe(int i , int j ,int N, int M){
    if(i >= 0 && i < N && j >= 0 && j < M)return true;
    
    return false;
}

int explore(queue<pair<int, pair<int, int> > >& q, int A, int B, int C, int D, int E, int F, vector<vector<int> >& visited, int &count){
    while(!q.empty()){
        int distance = q.front().first;
        int c = q.front().second.first;
        int d = q.front().second.second;
        q.pop();
        if ( c == E && d == F)return distance;
        visited[c][d] = 1;

        for(int i = 0; i < x.size(); i++){
            int first = c + x[i];
            int second = d + y[i];
            if(isSafe(first, second, A, B)){
                if(visited[first][second] == 0){
                    visited[first][second] = 1;
                    q.push({distance+1, {first, second}});
                }
            }
        }
    }
    return -1;
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector<vector<int> > visited (A, vector<int> (B, 0));
    
    int count  = 0;
    queue<pair<int, pair<int, int> > > q;
    q.push({0, {C-1, D-1}});
    return explore(q, A, B, C-1, D-1, E-1, F-1, visited, count);
}
