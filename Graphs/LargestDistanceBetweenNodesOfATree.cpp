pair<int, int> process(queue<pair<int, int> >& q, vector<int>& visited, unordered_map<int, vector<int> >& x){
    // Typical BFS with keeping track of the longest distance and farthest element.
    int maxi = INT_MIN, farthest = 0;
    while(!q.empty()){
        int node = q.front().first;
        int distance = q.front().second;
        q.pop();
        if(distance > maxi){
            maxi = distance;
            farthest = node;
        }
        visited[node] = 1;
        for(int i = 0; i < x[node].size(); i++){
            if(!visited[x[node][i]]){
                visited[x[node][i]] = 1;
                q.push({x[node][i], distance+1});
            }
        }
    }
    return {maxi, farthest};
}

int Solution::solve(vector<int> &A) {
    // Base Case
    if(A.size() <= 1)return 0;
    
    // Visited array to keep track of visited elements
    vector<int> visited(A.size(), 0);
    
    // Map to make the graph from given array
    unordered_map<int, vector<int> > x;
    x.clear();
    
    for(int i = 0; i < A.size(); i++){
        // If the value is -1, it doesn't have any parent.
        // Make the pairs in the adj. list type map
        if( A[i] != -1){
            x[A[i]].push_back(i);
            x[i].push_back(A[i]);
        }
    }
    
    // Start from the first element in the array and mark it visited.
    queue<pair<int, int> > q;
    q.push({0, 0});
    visited[0] = 1;

    // Gets the farthest element from the first element
    int farthest = process(q, visited, x).second;

    vector<int> vis(A.size(), 0);
    
    // Now apply BFS on the farthest element found and return the distance
    // of the farthest element found so far.
    q.push({farthest, 0});
    vis[farthest] = 1;
    return process(q, vis, x).first;
}
