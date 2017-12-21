void make(vector<int>& A, int curr, vector<bool> visited, vector<int> temp, vector<vector<int> >& ans){
    int n = A.size();
    
    curr = curr%n;
    
    for(int i = curr; i < n; i++){
        if(!visited[i]){
            vector<int> temp1(temp);
            vector<bool> visited1(visited);
            temp1.push_back(A[i]);
            visited1[i] = true;
            make(A, i+1, visited1, temp1, ans);
        }
    }
    
    for(int i = 0; i < curr; i++){
        if(!visited[i]){
            vector<int> temp1(temp);
            vector<bool> visited1(visited);
            temp1.push_back(A[i]);
            visited1[i] = true;
            make(A, i+1, visited1, temp1, ans);
        }
    }
    
    if(temp.size() == n){
        ans.push_back(temp);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int> > ans;
    vector<bool> visited(A.size(), false);
    vector<int> temp;
    make(A, 0, visited, temp, ans);
    
    return ans;
}
