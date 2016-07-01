// https://www.interviewbit.com/problems/reverse-bits/

unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    unsigned int num = 0;
    int bits = 31;
    int i = 0;
    while(A){
        num = num + pow(2,31-i)*(A%2);
        A = A/2;
        i++;
    }
    
    return num;
}
