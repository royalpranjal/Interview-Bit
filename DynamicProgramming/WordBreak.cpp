bool search(string A, vector<string> B){
    for(int i = 0; i < B.size(); i++){
        if(B[i] == A){
            return true;
        }
    }
    
    return false;
}

int Solution::wordBreak(string A, vector<string> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
 
    vector<int> temp(n+1, 0);
    temp[n] = 1;
    
    for(int i = n-1; i >= 0; i--){
        for(int j = i; j < n; j++){
            string s = A.substr(i, j-i+1);
            if(search(s, B) && temp[j+1] == 1){
                temp[i] = 1;
                break;
            }
        }
    }
    
    return temp[0];

}
