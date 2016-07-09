// https://www.interviewbit.com/problems/number-of-1-bits/

int Solution::numSetBits(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int sol = 0;
    while(A/2 != 0){
        if(A%2 != 0){
            sol++;
        }
        A = A/2;
    }
    if(A%2 != 0){
        sol++;
    }

    return sol;
}

