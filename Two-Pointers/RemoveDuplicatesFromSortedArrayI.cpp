// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() == 0){
        return A.size();
    }
    
    int k = 0;
    for(int i = 1; i < A.size(); i++){
        if(A[k] != A[i]){
            A[k+1] = A[i];
            k++;
        }
    }
    
    A.erase(A.begin()+k+1, A.end());
    return k+1;
    
}
