// https://www.interviewbit.com/problems/array-3-pointers/

int checkMax(int a, int b, int c){
    int max = a;
    if(max < b){
        max = b;
    }
    if(max < c){
        max = c;
    }
    
    return max;
}

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i = 0, j = 0, k = 0;
    int sol = INT_MAX;
    int temp, temp1, temp2, temp3;
    
    while(i < A.size() || j < B.size() || k < C.size()){
        sol = min(sol, checkMax(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])));
        
        if(i+1 < A.size()){
            temp1 = checkMax(abs(A[i+1] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i+1]));
        }
        else{
            temp1 = INT_MAX;
        }
        if(j+1 < B.size()){
            temp2 = checkMax(abs(A[i] - B[j+1]), abs(B[j+1] - C[k]), abs(C[k] - A[i]));
        }
        else{
            temp2 = INT_MAX;
        }
        if(k+1 < C.size()){
            temp3 = checkMax(abs(A[i] - B[j]), abs(B[j] - C[k+1]), abs(C[k+1] - A[i]));
        }
        else{
            temp3 = INT_MAX;
        }

        temp = min(temp1, temp2);
        temp = min(temp, temp3);
        
        if(temp == INT_MAX){
            return sol;
        }
        else if(temp == temp1){
            i++;
        }
        else if(temp == temp2){
            j++;
        }
        else{
            k++;
        }
        
    }
    
    
    return sol;
}
