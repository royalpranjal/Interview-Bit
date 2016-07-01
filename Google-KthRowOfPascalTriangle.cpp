//https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

int C(int line, int i){
    if(i == 0){
        return 1;
    }
    return C(line, i-1)*(line-i+1)/i;
}

vector<int> Solution::getRow(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> sol;

    if(A == 0){
        sol.push_back(1);
        return sol;
    }
    
    for(int i = 0; i <= A; i++){
        sol.push_back(C(A, i));    
    }
    
    return sol;
    
}
