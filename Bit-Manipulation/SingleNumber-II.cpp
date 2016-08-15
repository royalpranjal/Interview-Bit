// https://www.interviewbit.com/problems/single-number-ii/

int Solution::singleNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size() == 0){
        return 0;
    }
    
    int first = 0, second = 0;
    for(int i = 0; i < A.size(); i++){
        second = second | (first & A[i]);
        first = first ^ A[i];
        int check = ~(first & second);
        first = first & check;
        second = second & check;
    } 
    
    return first;
}
