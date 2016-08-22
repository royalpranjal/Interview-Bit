// https://www.interviewbit.com/problems/rain-water-trapped/

int chooseMax(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int chooseMin(int a, int b){
    if(a > b){
        return b;
    }
    return a;
}

int Solution::trap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() == 0){
        return 0;
    }
    
    vector<int> left(A.size());
    vector<int> right(A.size());
    
    left[0] = A[0];
    for(int i = 1; i < A.size(); i++){
        left[i] = chooseMax(left[i-1], A[i]);
    }
    
    right[A.size()-1] = A[A.size()-1];
    for(int i = A.size()-2; i >= 0; i--){
        right[i] = chooseMax(right[i+1], A[i]);
    }
    
    int ans = 0;
    
    for(int i = 0; i < A.size(); i++){
        ans = ans + chooseMin(left[i], right[i]) - A[i];
    }
    
    return ans;
    
}
