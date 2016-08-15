// https://www.interviewbit.com/problems/trailing-zeros-in-factorial/

int num(int i){
    int j = 1;
    int num = 1;
    while(j <= i){
        num = num*5;
        j++;
    }
    return num;
}

int Solution::trailingZeroes(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int count = 0;
    int i = 1;
    while(num(i) <= A){
        count = count + (A/num(i));
        i++;
    }
    
    return count;
}
