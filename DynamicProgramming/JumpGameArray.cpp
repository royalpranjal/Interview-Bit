// https://www.interviewbit.com/problems/jump-game-array/

int Solution::canJump(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() == 0 || A.size() == 1){
        return 1;
    }
    
    vector<int> temp(A.size(), 0);
    
    int closest = A.size()-1;
    
    for(int i = temp.size()-2; i >= 0; i--){
        if(A[i] - closest + i >= 0){
            closest = i;
            temp[i] = 1;
        }
    }
    
    return temp[0];
}
