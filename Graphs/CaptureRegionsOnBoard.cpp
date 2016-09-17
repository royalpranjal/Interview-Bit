// https://www.interviewbit.com/problems/capture-regions-on-board/

void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int rows = A.size();
    
    if(rows == 0){
        return;
    }
    
    int cols = A[0].size(); 
    
    vector<vector<bool> > check(rows, vector<bool>(cols, false));
    
    queue<pair<int, int> > q;
    
    for(int i = 0; i < cols; i++){
        if(A[0][i] == 'O'){
            check[0][i] = true;
            q.push(make_pair(0, i));
        }
        if(A[rows-1][i] == 'O'){
            check[rows-1][i] = true;
            q.push(make_pair(rows-1, i));
        }
    }
    
    for(int i = 0; i < rows; i++){
        if(A[i][0] == 'O'){
            check[i][0] = true;
            q.push(make_pair(i, 0));
        }
        if(A[i][cols-1] == 'O'){
            check[i][cols-1] = true;
            q.push(make_pair(i, cols-1));
        }
    }
    
    int i, j;
    
    while(!q.empty()){
        i = q.front().first;
        j = q.front().second;
        
        q.pop();
        
        if(i-1 > 0 && A[i-1][j] == 'O' && check[i-1][j] == false){
            check[i-1][j] = true; 
            q.push(make_pair(i-1, j));
            
        } 
        if(i+1 < rows-1 && A[i+1][j] == 'O' && check[i+1][j] == false){
            check[i+1][j] = true; 
            q.push(make_pair(i+1, j));
            
        } 
        if(j-1 > 0 && A[i][j-1] =='O' && check[i][j-1] == false){
            check[i][j-1] = true; 
            q.push(make_pair(i, j-1));
            
        } 
        if(j+1 < cols-1 && A[i][j+1] == 'O' && check[i][j+1] == false){
            check[i][j+1] = true; 
            q.push(make_pair(i, j+1));
            
        } 
    }
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(A[i][j] == 'O' && !check[i][j]){
                A[i][j] = 'X';
            }
        }
    }
    
}
