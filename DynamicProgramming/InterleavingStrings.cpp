// https://www.interviewbit.com/problems/interleaving-strings/

int Solution::isInterleave(string A, string B, string C) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int a = A.size(), b = B.size(), c = C.size();
    
    if((a + b) != c){
        return 0;
    }
    
    vector<vector<int> > temp(a+1, vector<int>(b+1, 0));
    
    temp[0][0] = 1;
    
    for(int i = 1; i < temp.size(); i++){
        if(C[i-1] == A[i-1]){
            temp[i][0] = temp[i-1][0];
        }
    }
    
    for(int i = 1; i < temp[0].size(); i++){
        if(C[i-1] == B[i-1]){
            temp[0][i] = temp[0][i-1];
        }
    }
    
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if((C[i+j-1] == A[i-1]) && (C[i+j-1] == B[j-1])){
                temp[i][j] = max(temp[i-1][j], temp[i][j-1]);
            }
            else if(C[i+j-1] == A[i-1]){
                temp[i][j] = temp[i-1][j];
            }
            else if(C[i+j-1] == B[j-1]){
                temp[i][j] = temp[i][j-1];
            }
        }
    }
    
    // for(int i = 0; i <= a; i++){
    //     for(int j = 0; j <= b; j++){
    //         cout << temp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
        
    
    return temp[a][b];
}
