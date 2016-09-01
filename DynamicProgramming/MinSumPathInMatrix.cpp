// https://www.interviewbit.com/problems/min-sum-path-in-matrix/

int Solution::minPathSum(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() == 0){
        return 0;
    }
    
    int rows = A.size();
    int cols = A[0].size();
    
    vector<vector<int> > temp(rows, vector<int>(cols));
    
    int sum = 0;
    
    for(int i = 0; i < cols; i++){
        temp[0][i] = sum + A[0][i];
        sum = temp[0][i];
    }
    
    sum = 0;
    
    for(int i = 0; i < rows; i++){
        temp[i][0] = sum + A[i][0];
        sum = temp[i][0];
    }
    
    for(int i = 1; i < rows; i++){
        for(int j = 1; j < cols; j++){
            temp[i][j] = A[i][j] + min(temp[i-1][j], temp[i][j-1]);
        }
    }
    
    return temp[rows-1][cols-1];
}
