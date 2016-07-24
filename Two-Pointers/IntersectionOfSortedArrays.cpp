// https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i = 0;
    int j = 0;
    vector<int> sol;
    
    while((i < A.size()) && (j < B.size())){
        if(A[i] > B[j]){
            j++;
        }
        else if(A[i] < B[j]){
            i++;
        }
        else{
            sol.push_back(A[i]);
            i++;
            j++;
        }
    }
    
    return sol;
}
