// https://www.interviewbit.com/problems/find-duplicate-in-array/

int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i = (A.size()/2)+1;
    vector<int> T(i, 0);

    for(i = 0; i < A.size(); i++){
        if((A[i]%2) == 0){
            if(T[(A[i]/2)-1] == 0){
                T[(A[i]/2)-1] = A[i];
            }
            else{
                return A[i];
            }
        }
    }

    fill(T.begin(), T.end(), 0);

    for(i = 0; i < A.size(); i++){
        if((A[i]%2) != 0){
            if(T[A[i]/2] == 0){
                T[A[i]/2] = A[i];
            }
            else{
                return A[i];
            }
        }
    }
    return A[i];
}
