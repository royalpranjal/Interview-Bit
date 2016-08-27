// https://www.interviewbit.com/problems/black-shapes/ 

void dfs(vector<string> A, int i, int j, vector<vector<bool> >& visited, vector<vector<int> >& check){
    if(i < 0 || i >= A.size()){
        return;
    }
    if(j < 0 || j >= A[0].size()){
        return;
    }
    if(check[i][j] == 0 || visited[i][j]){
        return;
    }
    
    visited[i][j] = true;
    
    dfs(A, i-1, j, visited, check);
    dfs(A, i+1, j, visited, check);
    dfs(A, i, j-1, visited, check);
    dfs(A, i, j+1, visited, check);
}

int Solution::black(vector<string> &A) {
    // Do not write main() function.
    //Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() == 0){
        return 0;
    }
    
    vector<vector<int> > check(A.size(), vector<int> (A[0].size(), 0));
    vector<vector<bool> > visited(A.size(), vector<bool> (A[0].size(), false));
    
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[0].size(); j++){
            if(A[i][j] == 'X'){
                check[i][j] = 1;
            }
        }
    }
    
    
    int sol = 0;
    
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[i].size(); j++){
            if(A[i][j] == 'X' && !visited[i][j]){
                dfs(A, i, j, visited, check);
                sol++;
            }
        }
    }
    
    return sol;
}
