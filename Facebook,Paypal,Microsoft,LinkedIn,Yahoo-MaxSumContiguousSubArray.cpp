// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

int Solution::maxSubArray(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int maxSoFar = 0, overallMax = 0, check = 0, k = 0, min;
    
    for(int i = 0; i < A.size(); i++){
        maxSoFar = maxSoFar + A[i];
        if(maxSoFar < 0){
            maxSoFar = 0;
        }
        if(maxSoFar > overallMax){
            overallMax = maxSoFar;
        }
        if(A[i] < 0){
            k++;
            if(k == 1){
                min = A[i];
            }
            if(A[i] > min){
                min = A[i];
            }
            check++;
        }
    }
    
    if(check == A.size()){
        overallMax = min; 
    }
    
    return overallMax;
}
