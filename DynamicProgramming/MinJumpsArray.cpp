// https://www.interviewbit.com/problems/min-jumps-array/

int Solution::jump(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> temp(A.size(), 0);
    
    int i = -1, j = 1;
    int val = 0;
    
    while(j < A.size()){
        if(val == 0){
            i++;
            val = A[i];
            temp[j] = temp[i]+1;
        }
        else if(val != 0){
            if(A[i]+i >= j){
                temp[j] = max(temp[j-1], temp[j]);    
                val--;
                j++;
            }
            else{
                val = 0;
            }
        } 
        if(i == j){
            return -1;
        }
    }
    
    
    return temp[A.size()-1];
}
